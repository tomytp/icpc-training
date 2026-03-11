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
    v64 v(n);
    map<ll, ll> mp;
    forn(i, 0, n) {
        cin >> v[i];
        mp[v[i]]++;
    }

    v64 relevants;
    for (auto [k, x] : mp) {
        if (x < k) continue;
        relevants.push_back(k);
    }
    vector<v64> dp((ll) relevants.size(), v64(n));
    forn(i, 0, n) {
        forn(j, 0, (ll) relevants.size()) {
            if (i >= 1) dp[j][i] = dp[j][i-1];
            if (v[i] == relevants[j]) {
                dp[j][i]++;
            }
        }
    }

    while (m--) {
        ll a, b; cin >> a >> b;
        a--; b--;
        ll ans = 0;
        forn(j, 0, (ll) relevants.size()) {
            ll down = a ? dp[j][a-1] : 0;
            ll up = dp[j][b];
            if (up - down == relevants[j]) ans++;
        }
        cout << ans << ln;
    }

    return 0;
}