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
const ll MOD = 1000000007;

int main(){
    _;
    ll n, l; cin >> n >> l;
    vector<v64> g(n);
    forn (i, 0, l) {
        ll k; cin >> k;
        forn(j, 0, k) {
            ll x; cin >> x;
            g[i].push_back(x-1);
        }
    }

    v64 visited(n, 0);
    v64 filhos(n, 1);
    filhos.assign(l, 0);

    function<void (ll,ll)> dfs = [&](ll u, ll p) {
        visited[u] = true;

        for (auto v : g[u]) {
            if (!visited[v]) dfs(v, u);
            filhos[u] = (filhos[u] + filhos[v]) % MOD;
        }

    };

    dfs(0, -1);
    ll count2 = 0;
    forn(i, l, n) count2 += visited[i];
    cout << filhos[0] << " " << count2 << ln;

    return 0;
}