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
    ll n; cin >> n;
    v64 a(n), b(n);
    ll ta = 0, tb = 0;
    forn(i, 0, n) {
        cin >> a[i] >> b[i];
        ta += a[i];
        tb += b[i];
    }

    ll ra = 0, rb = 0;
    forn(i, 0, n) {
        if (a[i] > (tb - b[i])) {
            rb += a[i] - (tb - b[i]);
        }
        if (b[i] > (ta - a[i])) {
            ra += b[i] - (ta - a[i]);
        }
    }
    debug (ra);
    debug (rb);

    ta += ra;
    tb += rb;
    if (ta > tb) {
        rb += ta-tb;
    } else if (tb > ta) {
        ra += tb-ta;
    }

    cout << ra + rb << ln;

    return 0;
}