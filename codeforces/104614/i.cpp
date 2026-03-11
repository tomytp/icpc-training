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

// d = distance | p = from/path
void dijkstra(ll s, v64 &d, vector<set<ll>>& p) {
    ll n = g.size();
    d.assign(n, INF);
    p.assign(n, {});

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
                p[v] = {u};
                pq.push({-d[v], v});
            } if (d[u] + w_v == d[v]) {
                p[v].insert(u);
            }
        }
    }
}

int main(){
    _;
    ll n, m, a, b; cin >> n >> m >> a >> b;
    a--; b--;
    g.resize(n);
    ll tot_w = 0;
    map<p64, ll> custo;
    forn(i, 0, m) {
        ll u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        custo[{u, v}] = w;
        custo[{v, u}] = w;
        tot_w += w;
    }

    v64 d;
    vector<set<ll>> path;
    dijkstra(a, d, path);


    ll source = b;
    set<ll> pq;
    pq.insert(source);
    vector<bool> visited(n, false);
    while (pq.size()) {
        ll curr = *pq.begin();
        pq.erase(pq.begin());
        for (auto filho : path[curr]) {
            tot_w -= custo[{curr, filho}];
            if (!visited[filho]) {
                visited[filho] = true;
                pq.insert(filho);
            }
        }
    }

    cout << tot_w << ln;

    
    return 0;
}