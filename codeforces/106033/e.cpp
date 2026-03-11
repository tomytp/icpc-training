// Perfomance geral (seguro p/ CP)
 #pragma GCC optimize("O3,unroll-loops,fast-math")
 



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct dinitz {
    const bool scaling = true;
    ll lim;
    struct edge {
        ll to, cap, rev, flow;
        bool res;
        edge(ll to_, ll cap_, ll rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };

    vector<vector<edge>> g;
    vector<ll> lev, beg;
    ll F;
    dinitz(ll n) : g(n), F(0) {}

    void add(ll a, ll b, ll c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size()-1, true);
    }

    bool bfs(ll s, ll t) {
        lev = vector<ll>(g.size(), -1); lev[s] = 0;
        beg = vector<ll>(g.size(), 0);
        queue<ll> q; q.push(s);
        while (q.size()) {
            ll u = q.front(); q.pop();
            for (auto& i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                if (scaling and i.cap - i.flow < lim) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }

    ll dfs(ll v, ll s, ll f = INF) {
        if (!f or v == s) return f;
        for (ll& i = beg[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            ll foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi) continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }

    ll max_flow(ll s, ll t) {
        for (lim = scaling? (1<<30) : 1; lim; lim /= 2)
            while (bfs(s, t)) while (ll ff = dfs(s, t)) F += ff;
        return F;
    }
};


int main() {
    _;
    ll n, m; cin >> n >> m;
    dinitz din(n);
    forn(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        din.add(a, b, c);
    }

    ll flow = din.max_flow(0, n-1);
    
    vector<vector<p64>> g;
    forn(i, 0, n) {
        for (auto e : din.g[i]) {
            if (e.res) continue;
            if (!e.flow) continue;
            g[i].emplace_back(e.to, e.flow);
        }
    }
    
    vector<v64> paths;
    v64 pathLens;
    ll tot = 0;
    while (tot < flow) {
        v64 path;
        v64 visited(n);
        function<ll (ll, ll)> dfs = [&](ll u, ll mx) {
            visited[u] = 1;

            if (u == n-1) return mx;

            for (auto& v: g[u]) {
                if (!visited[v.first] && v.second) {
                    ll fx = dfs(v.first, min(mx, v.second));
                    if (fx == -1) continue;
                    path.push_back(v.first);
                    v.second -= fx;
                    return fx;
                }
            }
            return -1ll;
        };

        ll x = dfs(0, INF);
        path.push_back(0);
        reverse(path.begin(), path.end());
        tot += x;
        pathLens.push_back(x);
        paths.push_back(path);
    }


    cout << flow << ln;
    cout << paths.size() << ln;
    forn(i, 0, paths.size()) {
        cout << pathLens[i] << " " << paths[i].size() << " ";
        forn(j, 0, paths[i].size()) cout << paths[i][j] + 1 << " ";; cout << ln;
    }
    
    return 0;
}