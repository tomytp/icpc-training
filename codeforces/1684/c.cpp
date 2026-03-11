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

void solve() {
    ll n, m; cin >> n >> m;
    vector<v64> mat(n, v64 (m));
    forn(i, 0, n) forn(j, 0, m) cin >> mat[i][j];


    v64 iv_idx(n, -1);
    forn(i, 0, n) {
        ll count = 0;
        forn(j, 0, m-1) {
            if (mat[i][j] > mat[i][j+1]) iv_idx[i] = j, count++;
        }
        if (count > 1) {
            cout << -1 << ln;
            return;
        }
    }

    ll first_wrong = -1;
    forn(i, 0, n) {
        if (iv_idx[i] != -1) {
            first_wrong = i;
            break;
        }
    }

    if (first_wrong == -1) {
        cout << "1 1" << ln;
    }

    
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}