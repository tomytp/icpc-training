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
    v64 a(n), b(n), c(n), d(n);
    forn(i, 0, n) cin >> a[i] >> b[i] >> c[i] >> d[i];


    ll ans = 0;
    forn(i, 0, n) {
        if (b[i] > d[i]) ans += a[i] + b[i] - d[i];
        else if (a[i] > c[i]) ans += a[i] - c[i];
    }
    cout << ans << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}