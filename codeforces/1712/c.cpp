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
    v64 v(n); 
    forn(i, 0, n) cin >> v[i];
    vector<bool> zero(n+1);
    ll ans = 0;
    forn(k, 0, 30) {
        for (ll i = n-2; i >= 0; i--) {
            if (zero[v[i]]) v[i] = 0;
            if (zero[v[i+1]]) v[i+1] = 0;
            if (v[i] > v[i+1]) {
                zero[v[i]] = true;
                v[i] = 0;
                ans++;
            }
        }
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}