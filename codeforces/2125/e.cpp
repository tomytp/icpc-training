#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f3fll;

int add(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int main() {
    _;
    int T;
    cin >> T;
    // We'll process each test independently.
    while (T--) {
        int n, x;
        cin >> n >> x;
        if (n == 1) {
            // Any singleton from 1..x works.
            cout << x % MOD << ln;
            continue;
        }
        int k = n - 1;
        // quick zero check: if x < (n-1)*(n+2)/2 then answer is 0
        // (smallest max M would be (n-1)(n-2)/2 but per sketch they use this bound)
        ll min_x = ll(n - 1) * ll(n + 2) / 2;
        if (x < min_x) {
            cout << 0 << ln;
            continue;
        }
        int H = x - (n - 1); // maximum B = M - (n-1) for M up to x
        // dp[t][s] = # ways to choose t distinct values from {1..v} summing to s
        // we will build incrementally for v from 1..H
        // Only need up to t = k and s up to H.
        vector< vector<int> > dp(k+1, vector<int>(H+1, 0));
        dp[0][0] = 1;
        // iterate values v = 1..H
        forn(v, 1, H+1) {
            // update dp in reverse t
            for (int t = min<ll>(k, v); t >= 1; t--) {
                // for sum dimension
                for (int s = H; s >= v; s--) {
                    dp[t][s] = add(dp[t][s], dp[t-1][s-v]);
                }
            }
        }
        // Precompute prefix sums on dp[k]
        vector<int> pref(H+1, 0);
        pref[0] = dp[k][0];
        forn(i, 1, H+1) pref[i] = add(pref[i-1], dp[k][i]);
        // Now for each M from minimal M = n..x, B = M-(n-1) in [1..H], answer += pref[B]
        int ans = 0;
        for (int M = n; M <= x; M++) {
            int B = M - (n - 1);
            if (B >= 1 && B <= H) {
                ans = add(ans, pref[B]);
            }
        }
        cout << ans << ln;
    }
    return 0;
}
