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

ll prefix_good(ll x) {
    if (x <= 0) return 0;
    v64 primes = {2, 3, 5, 7};
    ll res = x;
    forn(mask, 1, 16) {
        ll prod = 1;
        ll count = 0;
        forn (i, 0, 4) {
            if (mask & (1 << i)) {
                prod *= primes[i];
                count++;
            }
        }
        ll term = x / prod;
        if (count & 1) res -= term;
        else res += term;
    }
    return res;
}

void solve() {
    ll l, r; cin >> l >> r;
    cout << prefix_good(r) - prefix_good(l-1) << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}