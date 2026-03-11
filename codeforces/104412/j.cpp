#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll LOG = 20;

vector<v64> g;
vector<set<ll>> antig;
vector<bool> visited;
vector<ll> tin, low;
vector<ll> good_edges;
vector<p64> bridges;
ll timer = 0;



struct dsu {
	vector<ll> id, len;

	dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (len[a] < len[b]) swap(a, b);
		len[a] += len[b], id[b] = a;
	}
};

dsu sdu(1);
void dfs(ll u, ll p = -1) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    bool parent_skipped = false; // Flag to skip parent only once

    for(ll v : g[u]) {
        if (v == p && !parent_skipped) { 
            parent_skipped = true; 
            continue; 
        }

        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                good_edges[u]--;
                good_edges[v]--;
                bridges.emplace_back(u, v);
            }
        }
    }
}

void find_bridges( ll n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    forn(i, 0, n) {
        if (!visited[i]) dfs(i);
    }
}


int main() {
    _;
    ll n, m, q; cin >> n >> m >> q;
    good_edges.assign(n, 0);
    g.resize(n);
    antig.resize(n);
    vector<p64> edg; edg.reserve(m);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        good_edges[a]++;
        good_edges[b]++;
        edg.emplace_back(a, b);
    }

    sdu = dsu(n);
    find_bridges(n);

    for (auto p : bridges) {
        if (good_edges[p.first] || good_edges[p.second]) continue;
        sdu.uni(p.first, p.second);
    }


    forn(i, 0, q) {
        ll a, b; cin >> a >> b;
        a--; b--;
        if (sdu.find(a) == sdu.find(b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}