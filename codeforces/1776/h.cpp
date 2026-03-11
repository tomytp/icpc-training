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
    v64 a(n), b(n), idx(n);
    forn(i, 0, n) cin >> a[n-i-1], a[n-i-1]--;
    forn(i, 0, n) cin >> b[n-i-1], b[n-i-1]--;
    forn(i, 0, n) idx[a[i]] = i;
    
    forn(i, 0, n-1) {
        if (idx[b[i]] > idx[b[i+1]]) {
            cout << n-i-1 << ln;
            return;
        }
    }
    cout << 0 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
