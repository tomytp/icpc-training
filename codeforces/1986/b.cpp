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

ll x[] = {1, 0, -1, 0};
ll y[] = {0, -1, 0, 1};

void solve() {
    ll n, m; cin >> n >> m;
    vector<v64> v(n, v64(m));
    forn(i, 0, n) forn(j, 0, m) cin >> v[i][j];

    forn(i, 0, n) {
        forn(j, 0, m) {
            ll mx = -1;
            forn(k, 0, 4) {
                if (i+x[k] < 0 || i+x[k] >= n || j+y[k] < 0 || j+y[k] >= m) continue;
                mx = max(mx, v[i+x[k]][j+y[k]]);
            }
            if (v[i][j] > mx) v[i][j] = mx;
        }
    }

    forn(i, 0, n) forn(j, 0, m) cout << v[i][j] << " \n"[j==m-1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}