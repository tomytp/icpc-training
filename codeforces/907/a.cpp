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
    ll a, b, c, k; cin >> a >> b >> c >> k;

    ll x1 = 2*a;
    if (x1 <= 2*k) {
        cout << -1 << ln;
        return 0;
    }

    ll x2 = 2*b;
    if (x2 <= 2*k) {
        cout << -1 << ln;
        return 0;
    }

    ll x3 = max(c, k);
    if (x3 > 2*c || x3 > 2*k || x3 >= b) {
        debug(x3);
        cout << -1 << ln;
        return 0;
    }

    cout << x1 << ln;
    cout << x2 << ln;
    cout << x3 << ln;

    return 0;
}