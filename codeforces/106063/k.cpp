#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void) 0
    #define debug(x) cout << __LINE__  << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll t; cin >> t;
    while (t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (b <= c) cout << 0 << ln;
        else if (d <= a) cout << 0 << ln;
        else if (c <= a && b <= d) cout << b - a << ln;
        else if (a <= c && d <= b) cout << d - c << ln;
        else if (a < c) {
            cout << b - c << ln;
        } else {
            cout << d - a << ln;
        }
    }
    return 0;
}