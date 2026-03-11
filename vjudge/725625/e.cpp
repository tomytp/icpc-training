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
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    
    if(a[n-1] == b[n-1]) {
        cout << n << ln;
        return;
    }
    
    vector<bool> visto(n + 1);
    for(ll i = n - 2; i >= 0; i--) {
        if(a[i] == b[i] ||
           a[i] == a[i + 1] || 
           b[i] == b[i + 1] || 
           visto[a[i]] || 
           visto[b[i]]) {
            cout << i+1 << ln;
            return;
        }

        visto[a[i + 1]] = true;
        visto[b[i + 1]] = true;
    }

    cout << 0 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}