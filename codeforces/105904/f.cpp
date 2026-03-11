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

int main(){
    _;
    ll n, k; cin >> n >> k;
    v64 t(n);
    forn(i, 0, n) cin >> t[i];
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll u , v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll mx = 0;
    function<ll (ll, ll, ll)> dfs = [&](ll u, ll parent, ll h) {
        ll ans = 0;


        for (auto v: g[u]) {
            if (v == parent) continue;
            ans += dfs(v, u, h+1);
        }

        if (t[u] > k) {
            mx = max(mx, h);
        }

        if ((ans || t[u] > k) && u != 0) {
            ans += 2;
        }
        return ans;
    };

    cout << dfs(0, -1, 0) - mx << ln;

    return 0;
}