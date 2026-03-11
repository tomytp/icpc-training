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

void solve() {
    ll n; cin >> n;
    v64 a(n);
    forn(i, 0, n) cin >> a[i];
    vector<v64> g(n);
    forn(i, 1, n) {
        ll p; cin >> p; p--;
        g[p].push_back(i);
    }

    function<ll (ll, ll)> dfs = [&](ll u, ll p) {

        ll mn = INF;
        for (auto v : g[u]) {
            if (v == p) continue;
            mn = min(mn, dfs(v, u));
        }

        if (u == 0) {
            return a[u] + mn;
        }

        if (mn == INF) {
            return a[u];
        }

        if (a[u] >= mn) {
            return mn;
        }

        return a[u] + ((mn - a[u]) / 2);
    };

    cout << dfs(0, -1) << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}