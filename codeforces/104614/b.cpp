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
    ll n, c; cin >> c >> n;

    v64 vec(n);

    forn(i,0,n) cin >> vec[i];

    vector<v64> mat(c+1, v64(c+1,0));

    mat[0][0] = 1;

    forn(i,0,n){
        for(ll x = c; x >= 0; x--){
            for(ll y = c; y >= 0; y--){
                if(mat[x][y] == 0) continue;
                if(x + vec[i] <= c) mat[x+vec[i]][y] = 1;
                if(y + vec[i] <= c) mat[x][y+vec[i]] = 1;
            }
        }
    }

    // forn(x,0,c+1){
    //     forn(y,0,c+1){
    //         cout << mat[x][y] << " ";
    //     }
    //     cout << ln;
    // }
    ll max_sum = 0; 
    ll min_diff = 0;
    ll max_x = 0;
    ll max_y = 0;

    forn(x,0, c+1){
        forn(y, 0, c+1){
            if(mat[x][y] == 0) continue;
            if(x+y < max_sum) continue;
            if(x+y == max_sum && abs(x-y) > min_diff) continue;

            max_x = x;
            max_y = y;
            max_sum = x+y;
            min_diff = abs(x-y);
        }
    }
    
    cout << max(max_x, max_y) << " " << min(max_x, max_y) << ln;
    return 0;
}