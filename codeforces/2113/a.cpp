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
    ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;
    if (y < x) {
        swap(x, y);
        swap(a, b);
    }


    ll count = 0;
    if (k >= a) {
        count = ((k-a) / x) + 1;
        debug(count);
        k = k - (x*count);
    }
    if (k >= b) {
        count += ((k-b) / y) + 1;
    }
    cout << count << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}