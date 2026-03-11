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

// Disjoint Set Union (Union-Find)
//
// Supports find with path compression and union by size to maintain dynamic connectivity of disjoint sets.
//
// complexity: O(alpha(N)) amortized per op, O(N)

struct dsu {
	vector<ll> id, sz;

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};


int main(){
    _;
    ll n, m, q; cin >> n >> m >> q;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 low(n), in(n);
    vector<bool> vis(n), art(n);
    ll t = 0;
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        in[u] = t++;
        low[u] = in[u];
        vis[u] = true;

        ll children = 0;
        ll child_low = INF;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (!vis[v]) {
                children++;
                dfs(v, u);
                child_low = min(child_low, low[v]);
            } else {
                low[u] = min(low[u], in[v]);
            }
        }

        low[u] = min(low[u], child_low);

        if (u == 0) {
            if (children > 1) art[u] = true;
        } else {
            if (child_low >= in[u] && children > 0) art[u] = true;
        }
    };

    dfs(0, -1);
    vis.assign(n, false);
    ll cur = 0;
    v64 root(n), nart(n, false);
    function<void (ll, ll)> dfs2 = [&](ll u, ll p) {
        vis[u] = true;
        root[u] = cur;

        if (art[u]){
            nart[root[u]] = true;
            return;
        }

        for (auto v : g[u]) {
            if (art[v] || vis[v]) continue;
            dfs2(v, u);
        }
    };

    forn(i, 0, n) {
        if (!vis[i]) dfs2(i, -1), cur++; 
    }

    vector<v64> tree(cur);
    set<p64> edges;
    forn(i, 0, n) {
        for(auto v : g[i]) {
            if (root[i] != root[v] && !edges.count({root[i], root[v]})) {
                tree[root[i]].push_back(root[v]);
                tree[root[v]].push_back(root[i]);
                edges.insert({root[i], root[v]});
                edges.insert({root[v], root[i]});
            }
        }
    }

    v64 a(q), b(q), c(q);
    vector<v64> queries(n);
    vector<bool> resp(q, true);
    dsu uf(n);

    forn(i, 0, q) {
        cin >> a[i] >> b[i] >> c[i];
        a[i] = root[a[i] - 1];
        b[i] = root[b[i] - 1];
        c[i] = root[c[i] - 1];
        queries[c[i]].push_back(i);
    }

    function<set<ll> (ll, ll)> solve = [&](ll u, ll p){
        set<ll> conj;
        conj.insert(u);

        for(auto v : tree[u]){
            if(v == p) continue;
            auto aux = solve(v, u);

            if(aux.size() > conj.size()) swap(aux, conj);
            for(auto s : aux) conj.insert(s);
        }

        for(auto x : queries[u]){
            if(!nart[u]) continue;
            if((conj.count(a[x]) || conj.count(b[x])) && (uf.find(a[x]) != uf.find(b[x]))) resp[x] = false;
        }

        for(auto v : tree[u]){
            if(v == p) continue;
            uf.uni(v, u);
        }
        vis[u] = true;
        return conj;
    };

    solve(0, -1);

    forn(i, 0, q){
        if(resp[i]) cout << "YES" << ln;
        else cout << "NO" << ln;
    }

    return 0;
}
