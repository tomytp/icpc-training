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

vector<vector<p64>> g;

void dijkstra(ll s, v64 &d, v64& p) {
    ll n = g.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<p64> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d_u = -pq.top().first;
        pq.pop();

        if (d_u != d[u]) continue;

        for (auto edge : g[u]) {
            ll v = edge.first;
            ll w_v = edge.second;

            if (d[u] + w_v < d[v]) {
                d[v] = d[u] + w_v;
                if (u == s) p[v] = v;
                else p[v] = p[u];
                pq.push({-d[v], v});
            }
        }
    }
}

struct edge {
    ll u, v, c;
};

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<edge> edges;

    g.resize(n);
    forn(i, 0, m) {
        ll a, b, l; cin >> a >> b >> l;
        a--; b--;
        g[a].emplace_back(b, l);
        g[b].emplace_back(a, l);
        edges.push_back({a, b, l});
    }

    vector<v64> ans(n, v64(n, INF));
    forn(i, 0, n) {
        v64 d, p;
        dijkstra(i, d, p);
        
        forn(j, 0, m) {
            auto [u, v, c] = edges[j];
            ll f1 = p[u], f2 = p[v];
            ll cost = c + d[u] + d[v];
            
            if (f1 > f2) swap(f1, f2), swap(u, v) ;
            if (f1 == -1) {
                if (f2 == v) continue;
                ans[min(u, v)][max(u, v)] = min(ans[min(u, v)][max(u, v)], cost);
                continue; 
            }
            if (f1 == f2) continue;
            ans[min(f1, i)][max(f1, i)] = min(ans[min(f1, i)][max(f1, i)], cost);
            ans[min(f2, i)][max(f2, i)] = min(ans[min(f2, i)][max(f2, i)], cost);
        }
    }

    forn(i, 0, m) {
        cout << (ans[min(edges[i].u, edges[i].v)][max(edges[i].u, edges[i].v)] != INF ? ans[min(edges[i].u, edges[i].v)][max(edges[i].u, edges[i].v)] - edges[i].c : -1) <<  ln;
    }


    
    return 0;
}