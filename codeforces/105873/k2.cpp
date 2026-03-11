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

const ll INF = 0x3f3f3f3f3f3fll;


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
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (ll ff = dfs(s, t)) F += ff;
		return F;
	}

	void reset() {
		F = 0;
		for (auto& edges : g) for (auto& e : edges) e.flow = 0; 
	}
};

vector<bool> visited;

void dfs(ll v, vector<v64>& g, vector<ll> &out) {
    visited[v] = true;
    for(auto u : g[v]) if(!visited[u]) dfs(u, g, out);
    out.push_back(v);
}

vector<v64> scc(vector<v64>& g, v64& cost, v64& cost_or) {
    int n = g.size();
    v64 order, roots(n, 0);

    vector<v64> adj_rev(n);
    forn(u, 0, n) for (ll v : g[u]) adj_rev[v].push_back(u);

    visited.assign(n, false);
    forn(i, 0, n) if (!visited[i]) dfs(i, g, order);
    reverse(order.begin(), order.end());
    
    visited.assign(n, false);
    ll curr_comp = 0;
    for (auto v : order) {
        if (!visited[v]) {
            v64 component; dfs(v, adj_rev, component);
            for (auto u : component) roots[u] = curr_comp;
            curr_comp++;
        }
    }

    cost.resize(curr_comp);
    forn(i, 0, n) {
        cost[roots[i]] += cost_or[i];
    }

    set<p64> edges;
    vector<v64> cond_g(curr_comp);
    forn(u, 0, n) {
        for (auto v : g[u]) {
            if (roots[u] != roots[v] && !edges.count({roots[u], roots[v]})) {
                cond_g[roots[u]].push_back(roots[v]);
                edges.emplace(roots[u], roots[v]);
            }
        }
    }
    return cond_g;          
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 cost(n);
    forn(i, 0, n) cin >> cost[i];
    vector<v64> g(n);
    forn(i, 0, n) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    v64 c2;
    g = scc(g, c2, cost);
    n = g.size();
    swap(c2, cost);

    ll source = n;
    ll tink = n+1;
    dinitz fft(n+2);
    ll sum = 0;
    forn(i, 0, n) {
        if (cost[i] > 0) {
            sum += cost[i];
            fft.add(source, i, cost[i]);
        } else {
            fft.add(i, tink, -cost[i]);
        }
    }

    forn(u, 0, n) {
        for (auto v: g[u]) {
            fft.add(v, u, INF);
        }
    }

    cout << sum - fft.max_flow(source, tink) << ln;
    return 0;
}