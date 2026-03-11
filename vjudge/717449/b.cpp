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

v64 topo_sort(vector<v64>& g) {
	v64 indeg(g.size()), q;
	for (auto& li : g) for (int x : li) indeg[x]++;
	forn(i, 0, g.size()) if (indeg[i] == 0) q.push_back(i);
	forn(j, 0, q.size()) for(int x : g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
	return q;
}

int main(){
    _;
    ll n; cin >> n;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];
    set<p64> edges;
    vector<v64> g(26);
    forn(i, 0, n-1) {
        ll curr = 0;
        while (curr <= v[i].size() && curr <= v[i+1].size() && v[i][curr] == v[i+1][curr]) {
            curr++;
        }

        if (curr >= v[i+1].size()) {
            cout << "Impossible" << ln;
            return 0;
        }
        if (curr >= v[i].size()) continue;

        if (!edges.count({v[i][curr], v[i+1][curr]})) {
            debug((ll)(v[i][curr] - 'a'));
            g[v[i][curr] - 'a'].push_back(v[i+1][curr] - 'a');
            edges.insert({v[i][curr], v[i+1][curr]});
        }
    }

    auto topo = topo_sort(g);

    // forn(i, 0, 26) {
    //     for (auto u : g[i]) {
    //         cout << i << " " << u << ln;
    //     }
    // }
    
    if (topo.size() != g.size()) {
        cout << "Impossible" << ln;
        return 0;
    }

    forn(i, 0, 26) cout << (char) (topo[i] + 'a');
    cout << ln;
    
    return 0;
}