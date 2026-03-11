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

ll naa, maa;
bool floyd_warshall(vector<v64>& d) {
	for (ll k = 0; k < naa; k++)
	for (ll i = 0; i < naa; i++)
	for (ll j = 0; j < naa; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (ll i = 0; i < naa; i++)
		if (d[i][i] < 0) return 1;

	return 0;
}

// MinCostMaxFlow
//
// min_cost_flow(s, t, f) computa o par (fluxo, custo)
// com max(fluxo) <= f que tenha min(custo)
// min_cost_flow(s, t) -> Fluxo maximo de custo minimo de s pra t
// Se for um dag, da pra substituir o SPFA por uma DP pra nao
// pagar O(nm) no comeco
// Se nao tiver aresta com custo negativo, nao precisa do SPFA
//
// O(nm + f * m log n)

template<typename T> struct mcmf {
	struct edge {
		ll to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
		bool res; // se eh reversa
		T cost; // custo da unidade de fluxo
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false) {}
		edge(ll to_, ll rev_, ll flow_, ll cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
	};

	vector<vector<edge>> g;
	vector<ll> par_idx, par;
	T inf;
	vector<T> dist;

	mcmf(ll n) : g(n), par_idx(n), par(n), inf(numeric_limits<T>::max()/3) {}

	void add(ll u, ll v, ll w, T cost) {
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);

		g[u].push_back(a);
		g[v].push_back(b);
	}

	bool dijkstra(ll s, ll t, vector<T>& pot) {
		priority_queue<pair<T, ll>, vector<pair<T, ll>>, greater<>> q;
		dist = vector<T>(g.size(), inf);
		dist[s] = 0;
		q.emplace(0, s);
		while (q.size()) {
			auto [d, v] = q.top();
			q.pop();
			if (dist[v] < d) continue;
			for (ll i = 0; i < g[v].size(); i++) {
				auto [to, rev, flow, cap, res, cost] = g[v][i];
				cost += pot[v] - pot[to];
				if (flow < cap and dist[v] + cost < dist[to]) {
					dist[to] = dist[v] + cost;
					q.emplace(dist[to], to);
					par_idx[to] = i, par[to] = v;
				}
			}
		}
		return dist[t] < inf;
	}

	pair<ll, T> min_cost_flow(ll s, ll t, ll flow = INF) {
		vector<T> pot(g.size(), 0);
		dijkstra(s, t, pot); // mudar algoritmo de caminho minimo aqui

		ll f = 0;
		T ret = 0;
		while (f < flow and dijkstra(s, t, pot)) {
			for (ll i = 0; i < g.size(); i++)
				if (dist[i] < inf) pot[i] += dist[i];

			ll mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow,
					g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}

			ret += pot[t] * mn_flow;

			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				u = par[u];
			}

			f += mn_flow;
		}

		return make_pair(f, ret);
	}

	vector<pair<ll,ll>> recover() {
		vector<pair<ll,ll>> used;
		for (ll i = 0; i < g.size(); i++) for (edge e : g[i])
			if(e.flow == e.cap && !e.res) used.push_back({i, e.to});
		return used;
	}
};

int main(){
    _;
    cin >> naa >> maa;

    ll n, m;
    n = naa; m = maa;

    vector<v64> mat(n, v64(m));
    forn(i, 0, n) {
        forn(j, 0, m) {
            cin >> mat[i][j];
        }
    }
    vector<v64> adj(n, v64(n, -1));
    forn(i, 0, n) {
        forn(j, 0, n) {
            cin >> adj[i][j];
            if (adj[i][j] == -1) {
                adj[i][j] = INF;
            }
        }
    }

    floyd_warshall(adj);

    vector<v64> cost_item_w(n, v64(m,0));

    forn(p,0,m){
        forn(i,0,n){
            forn(j,0,n){
                cost_item_w[j][p] += adj[i][j]*mat[i][p];
            }
        }
    }

    ll flow_size = n + m + 2;
    
    ll source = flow_size - 1;
    ll tink = flow_size - 2;
    // 0  -> n - 1 WAREHOUSES
    // n -> n + (m-1) PRODUCTS

    mcmf<ll> flow(flow_size);

    forn(i, 0, m) {
        flow.add(source, n + i, 1, 0);
    }

    forn(i, 0, n) {
        flow.add(i, tink, 1, 0);
    }

    forn(i, 0, n) {
        forn(j, 0, m) {
            // produto J, warehouse I
            flow.add(n + j, i, 1, cost_item_w[i][j]);
        }
    }
    
    cout << flow.min_cost_flow(source, tink).second << ln;
    
    return 0;
}