#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }


#define pb push_back
const int MAXN = 2e5+5;
vector<int> g[MAXN];
vector<int> h[MAXN], hr[MAXN];

const int INF = 1e9;

void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> a(n,n);
	for(int i = 0; i < m;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	//acha d0
	vector<int> dbase(n,INF);
	queue<int> qbase;
	dbase[0] = 0;
	qbase.push(0);
	while(!qbase.empty()){
		int u = qbase.front(); qbase.pop();
		for(auto v : g[u]) if(dbase[v] == INF){
			dbase[v] = dbase[u]+1;
			qbase.push(v);
		}
	}
	int d0 = dbase[n-1];

	//lendo op
	vector<int> b(k);
	for(int i = 0; i < k; i++){
		cin >> b[i];
		b[i]--;
		a[b[i]] = i;
	}
	vector<int> ans(k+2);
	//busca binaria pra ver onde quebra
	int l = 0;
	int r = k;
	while(l < r){
		int M = (l+r+1)/2;
		queue<int> q;
		vector<int> dis(n,INF);
		dis[0] = 0;
		q.push(0);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto v : g[u]) if(a[v] >= M && dis[v] == INF){
				dis[v] = dis[u]+1;
				q.push(v);
			}
		}
		if(dis[n-1] == d0){
			l = M;
		}else{
			r = M-1;
		}
	}
	int FUNFA = l;
	//bfs do fim, pra saber a arvore de caminhos minimos
	queue<int> qfim;
	vector<int> dfim(n,INF);
	dfim[n-1] = 0;
	qfim.push(n-1);
	while(!qfim.empty()){
		int u = qfim.front(); qfim.pop();
		for(auto v : g[u]) if(dfim[v] == INF){
			dfim[v] = dfim[u]+1;
			qfim.push(v);
		}
	}
	
	//montando o grafo das arestas minimas
	vector<int> esta(n);
	for(int i = 0; i < n; i++){
		if(dbase[i]+dfim[i]==d0) esta[i] = 1;
	}
	for(int u = 0; u < n; u++){
		for(auto v : g[u]) if(esta[u] && esta[v] && dbase[u]+1 == dbase[v]){
			h[u].pb(v);
			hr[v].pb(u);
		}
	}
	vector<int> tempoida = a;
	vector<int> tempovolta = a;
	//resolvendo ida
	queue<int> q;
	vector<int> inq(n);
	inq[0] = 1;
	q.push(0);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int sz = hr[u].size();
		if(sz){
			int maxx = 0;
			for(auto v : hr[u]){
				maxx = max(maxx,tempoida[v]);
			}
			tempoida[u] = min(tempoida[u],maxx);
		}
		for(auto v : h[u]){
			if(!inq[v]){
				inq[v] = 1;
				q.push(v);
			}
		}
	}
	//resolvendo volta
	while(!q.empty()) q.pop(); //limpando
	for(int i = 0; i < n; i++) inq[i] = 0;
	inq[n-1] = 1;
	q.push(n-1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int sz = h[u].size();
		if(sz){
			int maxx = 0;
			for(auto v : h[u]){
				maxx = max(maxx,tempovolta[v]);
			}
			tempovolta[u] = min(tempovolta[u],maxx);
		}
		for(auto v : hr[u]){
			if(!inq[v]){
				inq[v]=1;
				q.push(v);
			}
		}
	}
	//achando total
	vector<int> tempo(n);
	for(int i = 0; i < n; i++){
		tempo[i] = min(tempovolta[i],tempoida[i]);
	}
	vector<vector<int>> ah(d0+1);
	for(int i = 0; i < n; i++) if(esta[i]){
		ah[dbase[i]].pb(tempo[i]);
	}
	for(int i = 1; i < d0; i++){
		vector<int> v = ah[i];
		int sz = v.size();
		if(sz == 1){
			ans[0]++;
		}
		else{
			sort(v.rbegin(),v.rend());
			int lim = min(v[1]+1,k+1);
			ans[lim]++;
		}
	}
	for(int i = 1; i <= k; i++) ans[i] += ans[i-1];
	for(int i = FUNFA+1; i <= k; i++) ans[i] = -1;
	for(int i = 0; i <= k; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
