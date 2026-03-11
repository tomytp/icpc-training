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

vector<pair<ll, ll>> get_cut(dinitz& g, ll s, ll t, ll& f) {
	f = g.max_flow(s, t);
	vector<pair<ll, ll>> cut;
	vector<ll> vis(g.g.size(), 0), st = {s};
	vis[s] = 1;
	while (st.size()) {
		ll u = st.back(); st.pop_back();
		for (auto e : g.g[u]) if (!vis[e.to] and e.flow < e.cap)
			vis[e.to] = 1, st.push_back(e.to);
	}
	for (ll i = 0; i < g.g.size(); i++) for (auto e : g.g[i])
		if (vis[i] and !vis[e.to] and !e.res) cut.emplace_back(i, e.to);
	return cut;
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    
    dinitz flow(2*n+2);

    // 0 = source
    // 2*n+1 = tink
    // i v_in
	// i+n v_out

	forn(i,1,n+1){
		flow.add(i+n, i, INF);
	}

	forn(i,0,m){
		ll a,b;
		cin >> a >> b;
		flow.add(a,b+n,1);
		flow.add(b,a+n,1);
	}

	flow.add(0,1,INF);
	flow.add(2*n,2*n+1,INF);
	ll f;
	auto vec = get_cut(flow, 0, 2*n+1, f);
	cout << f << ln;
	for(auto p: vec){
		cout << p.first << " " << p.second - n << ln;
	}
    return 0;
}