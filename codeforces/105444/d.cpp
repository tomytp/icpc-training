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
    ll n, w; cin >> n >> w;
    n++;
    v64 cap(n), cur(n);
    vector<v64> g(n);
    forn(i, 1, n) {
        ll p; cin >> p >> cap[i] >> cur[i];
        g[p].push_back(i);
    }

    v64 ans(n);
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        if (u == 0) ans[u] = w;
        else ans[u] = cap[u] - cur[u] + max(0ll, ans[p] - cap[u]);

        for (auto v : g[u]) {
            if (v == p) continue;
            debug(v);
            dfs(v, u);
        }
    };

    dfs(0, -1);

    ll mn = INF;
    forn(i, 0, n) mn = min(mn, ans[i]), debug(ans[i]);
    cout << mn << ln;

    return 0;
}