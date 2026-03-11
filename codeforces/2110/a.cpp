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
    sort(v.begin(), v.end());
    ll b_par = -1;
    ll b_impar = -1;
    ll e_par = -1;
    ll e_impar = -1;

    forn(i, 0, n) {
        if (v[i] & 1) {
            b_impar = i;
            break;
        }
    }

    forn(i, 0, n) {
        if (!(v[i] & 1)) {
            b_par = i;
            break;
        }
    }

    for (ll i = n-1; i >= 0; i--) {
        if (!(v[i] & 1)) {
            e_par = i;
            break;
        }
    }


    for (ll i = n-1; i >= 0; i--) {
        if ((v[i] & 1)) {
            e_impar = i;
            break;
        }
    }

    cout << min(b_par + (n-e_par - 1), b_impar + (n-e_impar-1)) << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}