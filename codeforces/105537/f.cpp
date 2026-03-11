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

    if(n == 1){
        cout << 2 << ln;
        return 0;
    }

    v64 vec(n);

    forn(i,0,n){
        ll h, m;
        char c;
        cin >> h >> c >> m;
        vec[i] = h*60+m;
    }

    forn(i,0,n-2){
        if(vec[i+2] - vec[i] <= 10){
            cout << 0 << ln;
            return 0;
        }
    }

    forn(i,0,n-1){
        if(vec[i+1] - vec[i] <= 10){
            cout << 1 << ln;
            return 0;
        }
    }

    cout << 2 << ln;
    return 0;
}