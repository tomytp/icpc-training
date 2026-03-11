#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x; cin >> x;
    ll has = 64 - __builtin_clzll(x);
    ll uses = __builtin_popcountll(x);
    if (uses == 1 || uses == has) {
        cout << -1 << ln;
        return;
    }
    ll y = 1;
    while ((2*y)+1 < x) {
        y <<= 1;
        y++;
    }
    cout << y << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}