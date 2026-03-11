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
    vector<vector<char>> v(9, vector<char> (9));
    forn(i, 0, 9) forn(j, 0, 9) cin >> v[i][j];
    ll x, y; cin >> x >> y;
    x--; y--;
    ll p = x % 3;
    ll q = y % 3;
    
    ll checked = 0;
    forn(i, 0, 3)
    forn(j, 0, 3) {
        if (v[i+p*3][j+q*3] == '.') checked++, v[i+p*3][j+q*3] = '!';
    }

    if (checked > 0) {
        forn(i, 0, 9) {
            forn(j, 0, 9) {
                cout << v[i][j];
                if ((j+1)%3 == 0 && j != 8) cout << " ";
                if (j == 8) cout << ln;
            }
            if ((i+1) % 3 == 0) cout << ln;
        }
    } else {
        forn(i, 0, 9) {
            forn(j, 0, 9) {
                if (v[i][j] == '.') v[i][j] = '!';
                cout << v[i][j];
                if ((j+1)%3 == 0 && j != 8) cout << " ";
                if (j == 8) cout << ln;
            }
            if ((i+1) % 3 == 0) cout << ln;
        }
    }

    return 0;
}