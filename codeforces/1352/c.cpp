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
    ll n, k; cin >> n >> k;
    if (k < n) {
        cout << k << ln;
        return;
    }
    if (k == n) {
        cout << n+1 << ln;
        return;
    }
    k -= n;
    ll mult = (k / (n-1));
    ll resto = (k % (n-1));
    cout << n + ((n)*mult) + resto + 1 << ln;

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}