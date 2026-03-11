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

void dfs(ll u, ll parent, vector<v64>& g, v64& danger, v64& ans, v64& rev) {
    if (u == 0) {
        ans[u] = danger[u];
        rev[u] = min(0ll, danger[u]);
    } else {
        ans[u] = max(danger[u], danger[u] - rev[parent]);
        rev[u] = min(danger[u], danger[u] - ans[parent]);
    }
    for (auto v : g[u]) {
        if (v != parent) dfs(v, u, g, danger, ans, rev);
    }
}

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 ans(n);
    v64 rev(n);
    
    dfs(0, -1, g, v, ans, rev);
    forn(i, 0, n) {
        cout << ans[i] << " \n"[i==n-1];
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}