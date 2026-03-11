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
    ll n, m; cin >> n >> m;
    v64 v(n), pref(n);
    forn(i, 0, n) cin >> v[i];
    pref[0] = v[0];
    forn(i, 1, n) pref[i] = pref[i-1] + v[i];


    forn(i, 0, m) {
        ll d1, m1, d2, m2; cin >> d1 >> m1 >> d2 >> m2;

        m1--; m2--;
        bool inv = false;

        if(m2 < m1) inv = true;
        if(m2 == m1 && d2 < d1) inv = true;
        
        if(inv){
            swap(d1, d2);
            swap(m1, m2);
        }

        ll resp = 0;

        if(m1 == m2){
            resp = d2 - d1 + 1;
        }
        if(m1 < m2){
            resp = (v[m1] - d1 + 1) + (pref[m2-1] - pref[m1]) + d2;
        }

        if(inv) resp = pref.back() - resp + 2;

        cout << resp << ln;
    }   
}
 
int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}