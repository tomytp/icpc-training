#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)


const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _; 
	ll n, m; cin >> n >> m;

	vector<v64> g(n), ag(n);

	vector<p64> edg(m);
	
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--;
        b--;

		edg[i] = {a, b};
        g[a].push_back(b);
        ag[b].push_back(a);
    }
	vector<bool> vis(n); 
	v64 cnt(n);
	function<void (ll u, vector<v64>& graph)> prune = [&](ll u, vector<v64>& graph){
		vis[u] = true;
		cnt[u]++;
		
		for (auto v : graph[u]) {
			if (vis[v]) continue;
			prune(v, graph);
		}
	};
	prune(0, g); 
	vis.assign(n, false);
	prune(n-1, ag);
	g.assign(n, {});
	forn(i, 0, m) {
		if (cnt[edg[i].first] != 2 && cnt[edg[i].second] != 2) continue;
		if(edg[i].second == 0) continue; 
		g[edg[i].first].push_back(edg[i].second);
	}
	
	g[n-1].clear();
	v64 parent(n,-1);
	
	function<void (ll, ll)> dfs2 = [&](ll u, ll p){
		parent[u] = p;
		
		for(ll v : g[u]){
			if(parent[v] != -1) continue;
			dfs2(v,u);
		}
	};

	dfs2(0,-1);

	v64 position(n, -1);
	ll pos = 0;
	ll curr = n-1;
	while(curr != 0){
		position[curr] = pos++;
		curr = parent[curr];
	}
	position[0] = pos++;
	
	vector<p64> to_remove;
	v64 visited(n, false);

	function<void (ll, ll)> dfs = [&](ll u, ll pos_saida){
		visited[u] = true;
		if(position[u] != -1) pos_saida = position[u];
		for(ll v : g[u]){
			trace(
				cout << u << " " << v << ln;
			);		
			if(visited[v]){
				if(position[v] == -1) continue;
				ll prox_pos = position[v];
				if(prox_pos + 1 >= pos_saida) continue;
				to_remove.push_back({prox_pos+1, pos_saida-1});
				continue;
			}

			if(position[v] != -1){
				ll prox_pos = position[v];
				if(prox_pos + 1 < pos_saida) to_remove.push_back({prox_pos+1, pos_saida-1});
			}

			dfs(v, pos_saida);			
		}
	};
	
	dfs(0,0);

	ll k = sz(position);
	debugv(position);
	v64 mais(k);
	v64 menos(k); 
	debugm(to_remove);
	for(auto p: to_remove){
		mais[p.first]++;
		menos[p.second]++;
	}

	set<ll> valid;
	forn(i,0,k) valid.insert(i);
	
	ll open = 0;

	forn(t,0,k){
		debug(t);
		open += mais[t];
		debug(open);
		if(open) valid.erase(t);
		open -= menos[t];
	}
	
	debugv(valid);
	v64 resp;
	forn(i,0,n){
		if(valid.count(position[i])) resp.push_back(i);
	}
	
	debugv(resp);

	cout << sz(resp) << ln;
	forn(i,0,sz(resp)) cout << resp[i]+1 << " \n"[i==(sz(resp)-1)];
	return 0;
}
