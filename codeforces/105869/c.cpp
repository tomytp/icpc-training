#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void) 0
#else
    #define trace(x) (void) 0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v ": "; for (auto x : v) cout << x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;
    vector<v64> grid(n, v64(m)), dpd(n, v64(m, 0)), dps(n, v64(m, 0));
    forn(i, 0, n){
        forn(j, 0, m){
            cin >> grid[i][j];
        }
    }

    for(ll i = n-1; i >=0 ; i--){
        for(ll j = m-1; j >=0 ; j--){
            if(i<(n-1)){
                dpd[i][j] = max(dpd[i][j], dpd[i+1][j]);
            }
            if(j<(m-1)){
                dpd[i][j] = max(dpd[i][j], dpd[i][j+1]);
            }
            dpd[i][j] += grid[i][j];
        }
    }

    forn(i, 0, n)
    forn(j, 0, m){
        if(i > 0){
            dps[i][j] = max(dps[i][j], dps[i-1][j]);
        }
        if(j>0){
            dps[i][j] = max(dps[i][j], dps[i][j-1]);
        }
        dps[i][j]+= grid[i][j];
    }

    ll best = 0;
    forn(i, 0, n)
    forn(j, 0, m){
        best = max(best, dps[i][j]+dpd[i][j]-grid[i][j]);
        if(i>0 and j>0 and i<(n-1)) best = max(best, dps[i-1][j] + grid[i][j] + grid[i][j-1] + dpd[i+1][j-1]);
        if(i>0 and j>0) best = max(best, dps[i-1][j] + grid[i][j-1] + dpd[i][j]);
        if(j>0 and i<(n-1)) best = max(best, dps[i][j-1] + grid[i][j] + dpd[i+1][j-1]);
        if(j>0) best = max(best, dps[i][j-1] + dpd[i][j]);
    }

    cout << best << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}