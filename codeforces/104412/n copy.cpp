#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n, k; cin >> n >> k;
    
    v64 vec(2*n);
    v64 t(2*n);

    ll resp = 0;

    forn(i,0,n){
        cin >> vec[i];
        vec[i+n] = vec[i];
    }
    forn(i,0,n){
        cin >> t[i];
        t[i+n] = t[i];
    }

    forn(i,0,n){
        ll t1 = 0;
        ll t2 = 0;
        forn(j,0,k){
            if(t[i+j] == 1){
                t1 += vec[i+j];
            }else{
                t2 += vec[i+j];
            }
        }
        ll j = k-1;
        while(t1 < t2){
            if(t[i+j] == 1){
                t1 -= vec[i+j];
            }else{
                t2 -= vec[i+j];
            }
        }
        resp = max(resp, t2);
    }
    cout << resp << ln;
    return 0;
}