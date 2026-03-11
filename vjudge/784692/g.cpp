#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll n, m;
vector<v64> g;
stack<ll> s;
vector<ll> id, art;
v64 low;

int dfs_art(ll i, ll& t, ll p = -1) {
	ll lo = id[i] = t++;
	s.push(i);
	for (ll j : g[i]) if (j != p) {
		if (id[j] == -1) {
			ll val = dfs_art(j, t, i);
			lo = min(lo, val);

			if (val >= id[i]) {
				art[i]++;
				while (s.top() != j) s.pop();
				s.pop();
			}
			// if (val > id[i]) aresta i-j eh ponte
		}
		else lo = min(lo, id[j]);
	}
	if (p == -1 and art[i]) art[i]--;
    low[i] = lo;
	return lo;
}

void compute_art_points() {
	id = vector<ll>(n, -1);
	art = vector<ll>(n, 0);
    low = v64(n, 0);
	ll t = 0;
	for (ll i = 0; i < n; i++) if (id[i] == -1) 
		dfs_art(i, t, -1);
}

void solve() {
    set<p64> nedg;
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        nedg.emplace(min(a, b), max(a, b));
    }
    
    g.clear();
    g.resize(n);
    forn(i, 0, n) {
        forn(j, i+1, n) {
            if (!nedg.count({i, j})) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    compute_art_points();
    vector<set<ll>> comps;

    v64 vis(n);
    function<set<ll> (ll, bool)> dff = [&](ll u, bool stt) {
        vis[u] = true;
        set<ll> ans = {u};
        
        for (auto v: g[u]) {
            if (vis[v]) continue;
            if (art[u] >= 1) {
                if (low[v] == id[u]) {
                    auto tmp = dff(v, false);
                    tmp.insert(u);
                    comps.push_back(move(tmp));
                    continue;
                } else if (low[v] > id[u]) {
                    comps.push_back(dff(v, false));
                } else {
                    auto tmp = dff(v, false);
                    if (sz(tmp) > sz(ans)) swap(tmp, ans);
                    for (auto x : tmp) ans.insert(x);
                }
            } else {
                auto tmp = dff(v, false);
                if (sz(tmp) > sz(ans)) swap(tmp, ans);
                for (auto x : tmp) ans.insert(x);
            }
        }
        return ans;
    };

    forn(i, 0, n) {
        if (!vis[i]) comps.push_back(dff(i,true));
    }

    v64 cor(n, -1);
    
    function<bool (ll, ll, ll)> ddd = [&](ll u, ll p, ll idx) {
        if(p == -1) cor[u] = 0;
        for(auto v : g[u]) if(v != p){
            if(!comps[idx].count(v)) continue;
            if(cor[v] != -1){
                if(cor[v] == cor[u]) return true;
                continue;
            }
            cor[v] = !cor[u];
            bool b = ddd(v,u,idx);
            if(b) return true;
        } 
        return false;
    };

    vector<bool> feliz(n, false);

    forn(c,0,sz(comps)){
        cor.assign(n, -1);
        if(!ddd(*comps[c].begin(), -1, c)) continue;
        for(ll pessoa : comps[c]) feliz[pessoa] = true;
    }

    debugv(feliz);
    ll resp = n;
    forn(i,0,n) resp -= feliz[i];
    cout << resp << ln;
}

int main(){
    _;
    cin >> n >> m;
    while (n != 0 && n != 0) {
        solve();
        cin >> n >> m;
    }
    return 0;
}