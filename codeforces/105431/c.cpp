#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sz(x) ((ll) x.size())

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    bool tres = false;
    if(n % 2 == 1){
        n -= 3;
        tres = true;
    }

    if(tres){
        cout << n/2 + 1 << ln;
        cout << 3 << " ";
        forn(i,0,n/2) cout << 2 << " ";
        cout << ln;
    } else{
        cout << n/2 << ln;
        forn(i,0,n/2) cout << 2 << " ";
        cout << ln;
    }
    return 0;
}