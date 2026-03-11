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

    forn(i,0,n){
        ll x, y; cin >> x >> y;
        if (x < 0){
            x *= -1;
            y *= -1;
        }   

        if(y == 0){
            if(x <= 200){
                cout << "S" << ln;
            }else{
                cout << "N" << ln;
            }
            continue;
        }

        if(y > 0){
            if(x+y <= 100){
                cout << "S" << ln;
            }else{
                cout << "N" << ln;
            }
            continue;
        }

        if(y < 0){
            if(x<= 100){
                if(y >= -100){
                    cout << "S" << ln;
                }else{
                    cout << "N" << ln;
                }
            } else if (x-y <= 200){
                cout << "S" << ln;
            }else{
                cout << "N" << ln;
            }
            continue;
        }
    }
    return 0;
}