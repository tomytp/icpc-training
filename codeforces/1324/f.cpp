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
    ll n; cin >> n;
    v64 a(n);
    forn(i, 0, n) cin >> a[i];
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    v64 bdown(n), tot(n);
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        bdown[u] = a[u] ? 1 : -1;
        tot[u] = bdown[u];

        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (bdown[v] > 0) bdown[u] += bdown[v];
            tot[u] += tot[v];
        }
    };

    dfs(0, -1);

    v64 ans(n);
    ans[0] = bdown[0];
    function<void (ll, ll)> dfs2 = [&](ll u, ll p) {
        for (auto v : g[u]) {
            if (v == p) continue;
            ll curr = bdown[v];
            if (bdown[v] < 0) {
                curr = max(curr, ans[u]-1);
            } else if (ans[u] >= 0 ) {
                curr = max(curr, ans[u]);
            }


            ans[v] = curr;
            dfs2(v, u);
        }
    };
    dfs2(0, -1);

    forn(i, 0, n) cout << ans[i] << " \n"[i==n-1];

    return 0;
}