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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

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
		g[edg[i].first].push_back(edg[i].second);
	}

	cnt.assign(n, 0);

	function<bool (ll u)> dfs = [&](ll u) {
		vis[u] = true;
		cnt[u]++;
		if (u == n-1) return true;

		shuffle(g[u].begin(), g[u].end(), rng);
		for (auto v : g[u]) {
			if (vis[v]) continue;
			if (dfs(v)) return true;
		}

		cnt[u]--;
		return false;
	};

	ll tot = 2000;
	forn(run, 0, tot) {
		vis.assign(n, false);
		dfs(0);
	}

	v64 ans;
	forn(i, 0, n) {
		if (cnt[i] == tot) ans.push_back(i);
	}

	cout << sz(ans) << ln;
	forn(i, 0, sz(ans)) cout << ans[i]+1 << " \n"[i==sz(ans)-1];

    return 0;
}
