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

ll pow(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll intermed = pow(a,b/2,mod);
    ll resp = (intermed*intermed)%mod;
    if(b%2 == 1) resp = (resp*a)%mod;
    return resp;
}

void solve(){
    ll a; cin >> a;

    ll b = 0;
    ll pot2 = 1;

    forn(k,1,33){
        ll a_pot_b_mod_2km1 = pow(a, b%pot2, 2*pot2);

        b = ((a% (2*pot2)) ^ a_pot_b_mod_2km1) % (2*pot2);
        debug(bitset<32>(b));
    }

    if(pow(a,b, (1ll<<32)) == (a ^ b)){
        cout << 1 << " " << b << ln;
    }else{
        cout << 0 << ln;
    }
}
int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();

    return 0;
}