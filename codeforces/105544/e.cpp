#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;
    ll x2i = 0, x1i= INF, y2i = 0, y1i = INF;
    v64 x1(n), x2(n), y1(n), y2(n);
    forn(i, 0, n){
        ll a, b, c, d; cin >> a >> b >> c >> d; c--; d--;
        x1i = min(x1i, a);
        x2i = max(x2i, c);
        y1i = min(y1i, b);
        y2i = max(y2i, d);
        
        x1[i] = a;
        y1[i] = b;
        x2[i] = c;
        y2[i] = d;
    }

    auto intersection = [&](ll u, ll v) {
        ll maxu = max(y1[u], y2[u]);
        ll minu = min(y1[u], y2[u]);
        ll maxv = max(y1[v], y2[v]);
        ll minv = min(y1[v], y2[v]);
        return !(maxu < minv || maxv< minu);
    };

    vector<v64> g(n);
    forn(i, 0, n) {
        forn(j, i+1, n) {
            if (intersection(i, j)) {
                if (x1[i] < x1[j]) {
                    g[i].push_back(j);
                } else {
                    g[j].push_back(i);
                }
            }
        }
    }

    vector<ll> ret(n, -1), vis(n, 0);
    ll pos = n-1, dag = 1;
    function<void(ll)> dfs = [&](int v){
        vis[v] = 1;
        for(auto u: g[v]) {
            if(vis[u] == 1) dag = 0;
            else if(!vis[u]) dfs(u);
        }
        ret[pos--] = v, vis[v] = 2;
    };

    for(ll i = 0; i < n; i++) if(!vis[i]) dfs(i);

    v64 dp(n);
    ll mx = 0;
    for (auto u : ret) {
        dp[u] += x2[u] - x1[u] + 1;
        mx = max(mx, dp[u]);
        for (auto v : g[u]) {
            ll my_cost = dp[u] + k;
            dp[v] = max(dp[v], my_cost);
        }
    }
    // forn(i, 0, n) cout << dp[i] << " \n"[i==n-1];
    ll delta = ((x2i-x1i+1) - mx)*(y2i - y1i +1);
    cout << max(delta, (ll)0) << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}