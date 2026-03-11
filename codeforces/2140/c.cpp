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
    v64 s1, s2, s3, s4;
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n) {
        if (i % 2 == 1) s1.push_back(2*v[i] - i);
        else s2.push_back(2*-v[i] + i);
        
        if (i % 2 == 1) s3.push_back(2*+v[i] + i);
        else s4.push_back(2*-v[i] - i);
        
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());

    ll ans = 0;
    forn(i, 0, n) ans += (i % 2 == 0 ? v[i] : -v[i]);
    
    if (n == 1) {
        cout << ans << ln;
        return;
    }
    
    ll bonus = max(s2.back() + s1.back(), s3.back() + s4.back());
    if (n&1) bonus = max(bonus, n-1);
    else bonus = max(bonus, n-2);

    if (bonus > 0) {
        ans += bonus;
    }
    
    cout << ans << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    
    return 0;
}