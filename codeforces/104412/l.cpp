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
const ll MAX = 501;

int main() {
    _;
    ll n; cin >> n;
    ll a, b, c; cin >> a >> b >> c;
    v64 vec(n);
    ll tot = 0;
    forn(i,0,n){
        cin >> vec[i];
        tot += vec[i];
    } 

    vector<v64> mat(MAX, v64(MAX));
    mat[0][0] = 1;
    forn(k,0,n){
        ll x = vec[k];
        for(ll i = MAX-1; i >= 0; i--){
            for(ll j = MAX-1; j >= 0; j--){
                if(mat[i][j] == 0) continue;
                if(i+x < MAX) mat[i+x][j] = 1; 
                if(j+x < MAX) mat[i][j+x] = 1; 
            }
        }
    }
    
    ll resp = INF;
    forn(i,0,MAX){
        forn(j,0,MAX){
            if(mat[i][j] == 0) continue;
            ll curr = max({(i+a-1)/a, (j+b-1)/b, (tot-i-j+c-1)/c});
            resp = min(curr, resp);
        }
    }
    cout << resp << ln;
    return 0;
}