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
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i] >> b[i];
    ll tot = 0;
    forn(i, 0, n) tot += b[i] * (n-1);
    v64 deltas(n);
    forn(i, 0, n) deltas[i] = a[i] - b[i];
    sort(deltas.rbegin(), deltas.rend());
    
    forn(i, 0, n) tot += deltas[i] * i;
    cout << tot << ln;
    return 0;
}