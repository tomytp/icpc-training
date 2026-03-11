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
    ll n; cin >> n;
    v64 a(n);
    vector<v64> g(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n-1) {
        ll x, y; cin >> x >> y;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    v64 sum(n);
    ll curr_ans = 0;
    ll mx = 0;
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        sum[u] = a[u];
        
        for (auto v: g[u]) {
            if (v == p) continue;
            dfs(v, u);
            sum[u] += sum[v];
            curr_ans += sum[v];
        }
    };
    
    ll tot = accumulate(a.begin(), a.end(), 0ll);
    function<void (ll, ll)> dfs2 = [&](ll u, ll p) {
        ll prev = curr_ans;
        for (auto v: g[u]) {
            if (v == p) continue;
            
            curr_ans += tot - 2*sum[v];
            mx = max(mx, curr_ans);
            dfs2(v, u);
            curr_ans = prev;
        }
    };
    
    
    dfs(0, -1);
    mx = curr_ans;
    dfs2(0, -1);
    cout << mx << ln;

    return 0;
}