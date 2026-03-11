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
    ll x; cin >> x;
    
    if (x == 1) {
        cout << 3 << ln;
        return;
    }

    ll ans = 3;
    v64 v = {1, 1, 3};
    while (v[0] < x) {
        v[0] = 2 * v[1] + 1;
        ans++;
        sort(v.begin(), v.end());
    }
    cout << ans << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}