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
    ll n, t; cin >> n >> t;
    vector<v64> v(n, v64(t));
    forn(i, 0, n) {
        forn(j, 0, t) {
            cin >> v[i][j];
        }
    }
    forn(i, 0, n) {
        forn(j, 1, t) {
            v[i][j] += v[i][j-1];
        } 
    }

    ll l, u; cin >> l >> u;
    v64 bizu(2*t, INF);
    for (ll i = t-1; i >= 0; i--) {
        forn(duration, l, u+1) {
            bizu[i] = min(bizu[i], bizu[i+duration+1]);
        }
    }


    return 0;
}