#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 fat(21,1);

ll esc(ll a, ll b){
    return fat[a]/(fat[b]*fat[a-b]); 
}

int main() {
    _;
    forn(i,2,21) fat[i] = i*fat[i-1];


    forn(n,0,21){
        forn(k,0,n+1){
            ll aux = esc(n,k);
            ll imp = ((n|k) == n);
            if(aux % 2 == imp){
                cout << "FELIZ " << n << " " << k << " # " << aux << " " << imp << ln;
            }else{
                cout << "TRISTE " << n << " " << k << " # " << aux << " " << imp << ln;
            }
        }
    }

    return 0;
}