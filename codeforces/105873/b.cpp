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

ll max_sub_sum(v64 &v){
    ll n = v.size();
    v64 dp(n);
    dp[0] = v[0];
    ll best = v[0];

    forn(i, 1, n){
        dp[i] = v[i]+ max((ll)0, dp[i-1]);
        best = max(best, dp[i]);
    }

    return best;
}

pair<ll,ll> add(pair<ll,ll> x, pair<ll,ll> y){
    return {x.first+y.first, x.second+y.second};
}

ll spiral(pair<ll,ll> curr, pair<ll,ll> dir, vector<v64> &grid, bool ccw){
    ll n = grid.size();
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    v64 v(n*n);
    forn(i, 0, n*n){
        v[i] = grid[curr.first][curr.second];
        visited[curr.first][curr.second] = true;

        auto new_curr = add(curr, dir);
        if((new_curr.first < 0) || (new_curr.first > n-1) || (new_curr.second < 0) || (new_curr.second > n-1) || visited[new_curr.first][new_curr.second]){
            if(ccw) dir = {-dir.second, dir.first};
            else dir = {dir.second, -dir.first};
        }   

        curr = add(curr, dir);
    }

    // for(auto x : v){
    //     cout << x << " ";
    // }
    // cout << ln;
    return max_sub_sum(v);
}


int main(){
    _; ll n; cin >> n;
    vector<v64> grid(n, v64(n));
    forn(i, 0, n){
        forn(j, 0, n){
            cin >> grid[i][j];
        }
    }

    ll best = -INF;

    best = max(best, spiral({0,0}, {1,0}, grid, true));
    best = max(best, spiral({0,0}, {0,1}, grid, false));
    best = max(best, spiral({n-1, 0}, {0, 1}, grid, true));
    best = max(best, spiral({n-1, 0}, {-1,0}, grid, false));
    best = max(best, spiral({n-1, n-1}, {-1,0}, grid, true));
    best = max(best, spiral({n-1, n-1}, {0,-1}, grid, false));
    best = max(best, spiral({0,n-1}, {0, -1}, grid, true));
    best = max(best, spiral({0,n-1}, {1,0}, grid, false));

    cout << max(0ll, best) << ln;
    return 0;
}