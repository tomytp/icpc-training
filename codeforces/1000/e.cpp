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
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    set<p64> bridges;
    vector<bool> visited(n);
    v64 in(n), low(n);
    ll t = 0;
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        in[u] = t++;
        low[u] = in[u];
        visited[u] = true;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (!visited[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], in[v]);
            }
        }

        for (auto v : g[u]) {
            if (v == p) continue;
            if (low[v] > in[u]) {
                bridges.insert({u, v});
                bridges.insert({v, u});
            }
        }
    };
    dfs(0, -1);

    v64 root(n, -1);
    t = 0;

    function<void (ll, ll)> ndfs = [&](ll u, ll rt) {
        root[u] = rt;

        for (auto v : g[u]) {
            if (root[v] == -1 && !bridges.count({u, v})) {
                ndfs(v, rt);
            }
        }
    };


    forn(i, 0, n) {
        if (root[i] == -1) {
            ndfs(i, t++);
        }
    }


    set<p64> edges;
    vector<v64> tree(t);
    forn(u, 0, n) {
        for (auto v : g[u]) {
            if (root[u] != root[v] && !edges.count({root[u], root[v]})) {
                tree[root[u]].push_back(root[v]);
                tree[root[v]].push_back(root[u]);
                edges.emplace(root[u], root[v]);
                edges.emplace(root[v], root[u]);
            }
        }
    }

    function<p64 (ll, ll, ll)> dist = [&](ll u, ll p, ll st) {
        p64 ans = {st, u};

        for (auto v : tree[u]) {
            if (v == p) continue;
            ans = max(ans, dist(v, u, st + 1));
        } 

        return ans;
    };
    auto ans = dist(0, -1, 0);
    auto ans2 = dist(ans.second, -1, 0);
    cout << ans2.first << ln;
    // forn(i, 0, n) cout << root[i] << " \n"[i==n-1];

    return 0;
}
