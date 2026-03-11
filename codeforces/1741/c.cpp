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

    ll ans = INF;
    forn(sz, 0, n + 1) {
        ll target = 0;
        forn(i, 0, sz) {
            target += v[i];
        }
        ll i = sz;
        ll cur = 0;
        ll cur_cnt = 0;
        ll mx = sz;
        while (i < n) {
            if (cur + v[i] == target) {
                mx = max(mx, cur_cnt + 1);
                cur = 0;
                cur_cnt = 0;
            } else if (cur + v[i] < target) {
                cur_cnt++;
                cur += v[i];
            } else {
                break;
            }
            i++;
        }
        if (i == n && cur == 0) {
            ans = min(ans, mx);
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