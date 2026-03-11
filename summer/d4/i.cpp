#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll G = 100'000'000;
const ll MAX = 1'000'000;

// Dijkstra's Shortest Paths
//
// Computes single-source shortest paths on non-negative weighted graphs using a priority queue.
//
// complexity: O((N + M) log N), O(N + M)

vector<vector<p64>> g;

// d = distance | p = from/path
void dijkstra(ll s, v64 &d) {
    ll n = g.size();
    d.assign(n, INF);

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
                pq.push({-d[v], v});
            }
        }
    }
}


map<p64, ll> _id;
ll xxx = 0;

ll id(ll a, ll ta) {
    auto it = _id.find({a, ta});
    if (it != _id.end()) return it->second;
    _id[{a, ta}] = xxx++;
    return xxx-1;
}

int main(){
    _;
    
    ll n, m, s, f; cin >> n >> m >> s >> f;
    s--, f--;
    vector<v64> terminais(n);

    g.resize(MAX);

    forn(i, 0, m) {
        ll a, ta, b, tb; cin >> a >> ta >> b >> tb;
        a--, ta--, b--, tb--;
        ll id_ta = id(a,ta);
        ll id_tb = id(b,tb);

        terminais[a].push_back(id_ta);
        terminais[b].push_back(id_tb);

        g[id_ta].emplace_back(id_tb, 1);
        g[id_tb].emplace_back(id_ta, 1);
    }
    
    ll ini = -1;
    ll fim = -1;
    forn(i,0,n){
        ll idx = xxx++;
        if(i == s){
            ini = idx;
        }
        if(i == f){
            fim = idx;
        }
        for(ll t: terminais[i]){
            g[idx].push_back({t, G/2});
            g[t].push_back({idx, G/2});
        }
    }

    
    v64 d;
    dijkstra(ini,d);
    
    ll magick = d[fim] - G;

    ll resp1 = magick/G;
    ll resp2 = magick%G;

    cout << resp1 << "  " << resp2 << ln;
    return 0;
}