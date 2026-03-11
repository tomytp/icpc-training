#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll gc = v[0];
    forn(i, 1, n) gc = gcd(gc, v[i]);
    
    ll oc = 0;
    forn(i, 0, n) if (gc == v[i]) oc++;
    if (oc) {
        cout << n-oc << ln;
        return;
    }

    ll mx = 0;
    forn(i, 0, n) v[i] /= gc, mx = max(mx, v[i]);
    mx++;
    v64 dp(mx, INF), prox;

    for (auto x : v) {
        prox = dp;
        prox[x] = 1;

        forn(val, 1, mx) {
            if (dp[val] != INF) {
                ll g = gcd(val, x);
                prox[g] = min(prox[g], dp[val] + 1);
            }
        }
        dp.swap(prox);
    }
    cout << n + dp[1] - 2 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}