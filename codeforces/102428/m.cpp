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
    ll n, x; cin >> n >> x;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    
    ll cur = 1;
    ll mx = 1;
    forn(i, 1, n) {
        if (v[i] - v[i-1] > x) {
            cur = 1;
        } else {
            cur++;
        }
        mx = max(mx, cur);
    }

    cout << mx << ln;

    return 0;
}