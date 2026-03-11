#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1'000'000'007;

ll func(ll n){
    if(n < 9) return n;
    
    if(n%2 == 0) return n/2;

    if(n > 25) return (n-9)/2;

    map<ll,ll> mp = { 
        {11, 4}, 
        {13, 5},
        {15, 6},
        {17, 8},
        {19, 9},
        {21, 9},
        {23, 9},
        {25, 9}
    };

    return mp[n];
}

int main() {
    _;
    ll n; cin >> n;
    cout << func(n)%MOD << ln;
    
    return 0;
}