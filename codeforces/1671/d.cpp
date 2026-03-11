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
    ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll mn = INF, mx = 0;
    ll ans = 0;
    
    forn(i, 0, n-1) {
        ans += abs(v[i] - v[i+1]);
    }
    
    forn(i, 0, n) {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    bool mx_border = v[0] == mx || v[n-1] == mx;
    bool mn_border = v[0] == mn || v[n-1] == mn;

    ll mn_c = (mn - 1);
    if (!mn_border) mn_c += (mn - 1);

    ll mmn_c = min(v[0], v[n-1]) - 1;
    ans += min(mn_c, mmn_c);



    if (x > mx) {
        ll mx_c = 0;
        mx_c += x - mx;
        if (!mx_border) mx_c += x - mx;

        ll mmx_c = x - max(v[0], v[n-1]);
        ans += min(mx_c, mmx_c);
    }

    cout << ans << ln;
    // cout << ans << " " << mx << " " << mn << ln;
    // cout << ans + (mn - 1) + (x > mx ? x - mx : 0) << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}