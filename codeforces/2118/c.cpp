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
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    bool broken = false;
    forn(pexi, 0, 63){
        if (broken) break;
        forn(i, 0, n) {
            if ((1ll<<pexi) > k){
                broken = true;
                break;
            }
            if (!(v[i]&(1ll<<pexi))) {
                v[i] += (1ll<<pexi);
                k -= (1ll<<pexi);
            }
        }
    }
    ll ans = 0;
    forn(i, 0, n) {
        ans += __builtin_popcountll(v[i]);
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}