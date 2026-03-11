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

vector<ll> color;
ll diam = 0, n, g;

// Floyd-Warshall Algorithm
//
// Computes all-pairs shortest paths and detects negative cycles using dynamic programming over path lengths.
//
// complexity: O(N^3), O(N^2)

vector<vector<p64>> d;

bool floyd_warshall() {

	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++){
		d[i][j].first = min(d[i][j].first, d[i][k].first + d[k][j].first);
		d[i][j].first = min(d[i][j].first, d[i][k].second + d[k][j].second);

        d[i][j].second = min(d[i][j].second, d[i][k].first + d[k][j].second);
		d[i][j].second = min(d[i][j].second, d[i][k].second + d[k][j].first);
    }
    return 0;
}


int main(){
    _; ll m; cin >> n >> m >> g;
    color.resize(n);
    d.resize(n, vector<p64>(n, {INF,INF}));

    forn(i, 0, n) cin >> color[i];
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        if(color[a] == color[b]){
            d[a][b].first = 1;
            d[b][a].first = 1;
        }else{
            d[a][b].second = 1;
            d[b][a].second = 1;
        }
    }

    floyd_warshall();
    
    ll resp = 0;

    // forn(i,0,n){
    //     forn(j,0, n){
    //         cout << d[i][j].first << "#" << d[i][j].second << "\t";
    //     }
    //     cout << ln;
    // }
    
    forn(i,0,n){
        forn(j,0,i){
            auto [a,b] = d[i][j];
 
            ll dist = -1;
            forn(ass,0,g+1){
                ll temp = min(a + ass, b + g-ass);
                dist = max(dist, temp);
            }
            resp = max(dist, resp);
        }
    }
    cout << resp << ln;
    return 0;
}
