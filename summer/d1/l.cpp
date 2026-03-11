#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll LOG = 33;
// const ll LOG = 4;

int main(){
    _;
    ll n, q; cin >> n >> q;
    v64 vec(n);
    v64 accxor(n);

    forn(i,0,n){
        cin >> vec[i];
        accxor[i] = vec[i]^(i == 0 ? 0 : accxor[i-1]);
    }

    vector<v64> bits(LOG, v64(n));
    vector<v64> accbits(LOG, v64(n));

    forn(i,0,n){
        ll logval = 64 - __builtin_clzll(vec[i]);
        if(vec[i] == 0) continue;
        bits[logval-1][i] = 1;
    }

    forn(j,0,LOG){
        forn(i,0,n){
            accbits[j][i] = bits[j][i] + (i == 0 ? 0 : accbits[j][i-1]); 
        }
    }

    auto sum = [&](ll l, ll r, v64& v){
        if(l == 0) return v[r];
        return v[r] - v[l-1];
    };

    forn(xxx, 0, q){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll base = accxor[r];
        if(l != 0) base ^= accxor[l-1];

        for(ll j = LOG-1; j >= 0; j--){
            ll amt = sum(l,r,accbits[j]);
            ll pot = 1ll<<j;
            
            debug(pot);
            debug(j);
            debug(base);
            debug(amt);
            debug(((base&pot) == 0));
            debug(2*pot-1);

            if((base&pot) == 0 && amt > 0){
                base ^= (2*pot - 1);
            }

            trace(cout << ln);
        }
        cout << base << ln;
        trace(cout << ln << ln;);
    }
    
    return 0;
}