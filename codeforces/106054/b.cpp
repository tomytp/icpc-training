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
const ll MOD = 998244353;

ll exp(ll b, ll e){
    if(e == 0) return 1;
    if(e == 1) return b;

    ll resp = 1;
    ll temp = exp(b,e/2);
    resp = (temp*temp) % MOD;
    if(e%2 == 1) resp = (b*resp)%MOD;
    return resp; 
}  

ll choose(ll n, ll k){
    ll num = 1;
    ll dem = 1;

    forn(i,0,k){
        num = (num*(n-i)) % MOD;
        dem = (dem*(i+1)) % MOD;
    }

    return (num*exp(dem, MOD-2))%MOD;
}


int main(){
    _; ll n, k; cin >> n >> k;
    v64 b(n-k+1), minimo(k, 0), diff(n-k+1);
    forn(i, 0, n-k+1) cin >> b[i];

    if(k == 1){
        cout << 1 << ln;
        return 0;
    }

    forn(i, 0, n-k){
        diff[i] = b[i+1]-b[i];
        if(i >= k) diff[i] += diff[i-k];
        minimo[(i%k)] = max(minimo[(i%k)], -diff[i]);
    }

    ll sum = b[0];
    forn(i, 0, k){
        sum -= minimo[i];
    }

    if(sum < 0){
        cout << 0 << ln;
        return 0;
    }

    cout << choose(sum+k-1, k-1) << ln;

    return 0;
}
