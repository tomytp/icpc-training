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
    ll n, m; cin >> n >> m;
    v64 vec(n+1,0);

    forn(i,0,m){
        v64 esc(n,0);
        ll x, y; cin >> x >> y;
        ll q1 = 0;
        ll q2 = 0;

        forn(j,0,n){
            cin >> esc[j];
            if(esc[j] == 1){
                q1++;
            }else{
                q2++;
            }
        } 

        if(y > x/(q1+1)){
            debug(1);
            debug(y);
            vec[n] += y;
        }else{
            debug(2);
            q1++;
            debug(x/q1);
            vec[n] += x/q1;
        }

        forn(j,0,n){
            if(esc[j] == 1){
                vec[j] += x/q1;
            }else{
                vec[j] += y;
            }
        }
    }

    forn(i,0,n+1) cout << vec[i] << " ";; cout << ln;
    return 0;
}
