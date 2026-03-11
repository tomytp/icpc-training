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

bool can_do(vector<vector<p64>>& g, v64& bat, ll target) {
    ll n = g.size();
    v64 dp(n, -1);
    dp[0] = 0;
    for (ll v = 0; v < n; ++v) {
        if (dp[v] < 0) continue;
        ll nxt = min(target, dp[v] + bat[v]);

        for (auto [u, w] : g[v]) {
            if (nxt >= w && nxt > dp[u])
                dp[u] = nxt;
        }
    }

    return dp[n - 1] >= 0;
}

void solve() {
    ll n, m; cin >> n >> m;
    v64 bat(n);
    forn(i, 0, n) cin >> bat[i];
    vector<vector<p64>> g(n);
    forn(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }


    ll l = 0, r = 1'000'000'000, ans = -1;
    while (l <= r) {
        ll mid = l + (r-l) / 2;

        if (can_do(g, bat, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}