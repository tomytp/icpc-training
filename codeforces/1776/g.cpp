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

ll n;

int main(){
    _;
    cin >> n;
    string s; cin >> s;
    if(n == 1){
        cout << (s[0] == 'W') << ln;
        return 0;
    }

    v64 pref(2*n - 1);
    pref[0] = (s[0] == 'W');
    forn(i, 1, 2*n-1) {
        pref[i] = pref[i-1];
        if (s[i] == 'W') pref[i]++; 
    }
    ll mx = 0;
    forn(i, 0, n) {
        ll l = (i == 0 ? 0 : pref[i-1]);
        ll r = pref[i + n-1];
        mx = max(mx, r - l);
    }
    cout << mx << ln;
    return 0;
}
 