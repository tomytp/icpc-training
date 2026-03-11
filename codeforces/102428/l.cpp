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


int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<string> v(n);
    vector<vector<ll>> component(n ,v64(m));
    ll curr_comp = 0;
    v64 l(n*m+1), r(n*m+1);

    forn(i, 0, n) cin >> v[i];
    
    forn(i, 0, n) {
        component[i][0] = ++curr_comp;
        l[curr_comp] = 0;
        r[curr_comp] = 0;
        forn(j, 1, m) {
            if (v[i][j] != v[i][j-1]) {
                curr_comp++;
                l[curr_comp] = j;
                r[curr_comp] = j;
            }
            component[i][j] = curr_comp;
            r[curr_comp] = j;
        }
    }

    vector<v64> g(++curr_comp);

    p64 last = {INF, INF};
    forn(i, 0, n-1) {
        forn(j, 0, m) {
            p64 curr = {component[i][j], component[i+1][j]};
            if (curr != last) {
                g[curr.first].push_back(curr.second);
                last = curr;
            }
        }
    }

    ll mx = 0;
    function<void (ll, ll, ll, ll, ll)> dfs = [&](ll u, ll p, ll lb, ll rb, ll h) {
        lb = max(lb, l[u]);
        rb = min(rb, r[u]);
        h++;
        if (rb < lb) return;
        if (rb-lb+1 < h) return;
        if (h == rb - lb + 1) {
            mx = max(mx, h);
            return;
        }
        for (auto ve : g[u]) {
            if (ve == p) continue;

            dfs(ve, u, lb, rb, h);
        }
    };

    forn(u, 0, curr_comp) {
        dfs(u, -1ll, -1, INF, 0);
    }

    cout << mx*mx << ln;

    return 0;
}