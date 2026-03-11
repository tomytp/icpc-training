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
    ll n, k; cin >> n >> k;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    forn(i, 0, n) {
        if (k - (a[i] + b[i]) >= 0) {
            ans++;
            k -= a[i] + b[i];
        } else {
            break;
        }
    }
    cout << ans << ln;

    return 0;
}