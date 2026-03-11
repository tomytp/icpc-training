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

#define debugv(v) trace({cout << #v": "; for (auto xx : v) cout<< xx << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n, k; cin >> n >> k;
    vector<v64> old(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--, b--;
        old[a].push_back(b);
        old[b].push_back(a);
    }

    v64 c(k);
    forn(i, 0, k) cin >> c[i];

    v64 comp(n);
    comp[0] = sz(old[0]) + 1;
    forn(i,1 ,n) {
        comp[i] = sz(old[i]);
    }

    v64 parent(n);
    function<void (ll, ll)> fp = [&](ll u, ll p) {
        parent[u] = p;
        for (auto v : old[u])  {
            if (v == p) continue;
            fp(v, u);
        }
    };
    fp(0,0);
    
    vector<vector<p64>> g(n);
    forn(u, 0, n) {
        for (auto v : old[u]) {
            if (v == parent[u]) continue;
            g[u].emplace_back(comp[v], v);
        }
        sort(g[u].rbegin(), g[u].rend());
    }

    ll x = c[0];
    ll qx = 0;
    ll y = -1;
    ll qy = 0;
    forn(i, 0, k) {
        if (c[i] == x) qx++;
        else {
            y = c[i];
            qy++;
        }
    }

    if (y == -1) {
        cout << n * x << ln;
        return;
    }

    if (x > y) {
        swap(x, y);
        swap(qx, qy);
    }
    
    v64 color(n, -1);

    function<void (ll, bool, bool)> dfs = [&](ll u, bool pode_cara, bool pode_barata){
        ll baratas = min(comp[u], qx);
        ll caras = comp[u] - baratas;
        debug(u);
        debug(baratas);
        debug(pode_barata);
        debug(caras);
        debug(pode_cara);

        if (!pode_barata) {
            caras--;
            color[u] = y; 
        } else if (!pode_cara) {
            baratas--;
            color[u] = x;
        }

        for (auto [lx, v] : g[u]) { 
            dfs(v, caras > 0, baratas > 0);
            if (color[v] == x) baratas--;
            else caras--;
        }

        if (comp[u] == 1) {
            if (pode_barata) color[u] = x;
            else color[u] = y;
            return;
        }

        if (color[u] != -1) return;

        if (baratas) color[u] = x;
        else color[u] = y;
    };

    dfs(0, true, true);

    debugv(color);

    ll sum = accumulate(color.begin(), color.end(), 0ll);
    cout << sum << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}