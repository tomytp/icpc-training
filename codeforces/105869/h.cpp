#pragma GCC optimize("O3,unroll-loops,fast-math")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void) 0
#else
    #define trace(x) (void) 0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v ": "; for (auto x : v) cout << x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n, m; cin >> n >> m;
    v64 dist(n, -1);
    vector<vector<p64>> g(n);
    vector<tuple<ll,ll,ll>> edges; edges.reserve(2*m);
    v64 indeg(n);
    ll id = 0;
    forn(i, 0, m) {
        ll a, b; string s;
        cin >> a >> s >> b;
        a--; b--;
        g[a].push_back({b, id});
        indeg[b]++;
        edges.emplace_back(a,b, id++);
        if (s == "--"){
            g[b].push_back({a, id});
            indeg[a]++;
            edges.emplace_back(b, a, id++);
        }
    }

    deque<ll> dq;
    forn(u, 0, n) if (indeg[u] == 0) dq.push_back(u);

    v64 topo; topo.reserve(n);
    while (!dq.empty()) {
        ll u = dq.front(); dq.pop_front();
        topo.push_back(u);
        for (auto [v, idv]: g[u]) if (dist[v] == -1){
            dq.push_back(v);
            dist[v] = 0;
        }
    }

    reverse(topo.begin(), topo.end());
    debugv(topo);
    for (auto u: topo)
        for (auto [v, idv]: g[u])
            if (dist[v] + 1 > dist[u]) dist[u] = dist[v] + 1;


    ll resp = 0;
    forn(i, 0, n) resp = max(resp, dist[i]);
    cout << resp << ln;
}
 
int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();

    return 0;
}