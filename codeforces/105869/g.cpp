#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll)x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void) 0
#else
    #define trace(x) (void) 0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v ": "; for (auto x : v) cout << x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << (x) << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXLOG = 20; 



void solve() {
    ll n, q, c; cin >> n >> q >> c;

    vector<vector<p64>> g(n);
    vector<vector<ll>> bl(MAXLOG, v64(n));
    vector<vector<ll>> parent(MAXLOG, v64(n));

    forn(i, 0, n-1) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        g[a].emplace_back(b, d);
        g[b].emplace_back(a, d);
    }

    v64 depth(n);
    v64 h(n);
    vector<p64> st;
    function<void (ll, ll, ll)> dfs = [&](ll u, ll p, ll w) {
        if (p != -1) depth[u] = depth[p]+w, h[u] = h[p]+1;
        st.emplace_back(depth[u], u);
        ll idx = lower_bound(st.begin(), st.end(), (p64){depth[u]-c, 0ll}) - st.begin();
        bl[0][u] = st[idx].second;
        if (p!= -1) parent[0][u] = p;

        for (auto [v, nw] : g[u]) {
            if (v == p) continue;
            dfs(v, u, nw);
        }

        st.pop_back();
    };
    dfs(0, -1, -1);

    forn(j,1,MAXLOG){
        forn(i,0,n){
            bl[j][i] = bl[j-1][bl[j-1][i]];
            parent[j][i] = parent[j-1][parent[j-1][i]];
        }
    }


    while (q--) {
        ll u, v; cin >> u >> v; 
        u--; v--;
        ll resp = 0;

        ll x = u, y = v;
        if (h[y] > h[x]) swap(x, y), swap(u, v);
        for (ll i = MAXLOG - 1; i >= 0; i--) {
            if (h[parent[i][x]] >= h[y]) x = parent[i][x];
        }

        function<ll (ll, ll)> f = [&](ll a, ll b){
            for (ll i = MAXLOG - 1; i >= 0; i--) {
                if (depth[bl[i][a]] > depth[b]){
                    a = bl[i][a];
                    resp += (1<<i);
                }
            }
            return a;
        };

        for (ll i = MAXLOG - 1; i >= 0; i--) {
            if (parent[i][x] != parent[i][y]) x = parent[i][x], y = parent[i][y];
        }

        ll lca = parent[0][x];

        if (x == y) {
            f(u,v);
            cout << resp << ln;
            continue;
        }

        
        ll auxu = f(u, lca);
        ll auxv = f(v, lca);
        ll d = depth[auxv] + depth[auxu] - 2*depth[lca];

        if(d > c) resp++;
        cout << resp << ln;
    }
}

int main() { 
    _;
    ll t; cin >> t;
    while (t--) solve();

    return 0;
}