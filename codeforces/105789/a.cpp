#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n, m; cin >> n >> m;

    vector<vector<vector<ll>>> gindo(n, vector<vector<ll>>(26));
    vector<vector<vector<ll>>> gvindo(n, vector<vector<ll>>(26));
    
    vector<vector<bool>> visitados(n, vector<bool>(n, false));

    queue<pair<ll,ll>> fila;
    ll ans = 0; 
    forn(i,0,n) visitados[i][i] = true;

    forn(i,0,m){
        ll a, b;
        char c;
        cin >> a >> b >> c;
        a--, b--;
        gindo[a][c-'a'].push_back(b);
        gvindo[b][c-'a'].push_back(a);

        if(a != b && visitados[a][b] == false){
            visitados[a][b] = true;
            fila.push({a,b});
            ans++;
            debug(ans);
        }
    }
    
    forn(i,0,n){
        forn(c,0,26){
            for(ll x: gvindo[i][c]){
                for(ll y: gindo[i][c]){
                    if(visitados[x][y]) continue;
                    visitados[x][y] = true;
                    fila.push({x,y});
                    ans++;
                    debug(ans);
                } 
            }
        }
    }

    while(!fila.empty()){
        auto [u, v] = fila.front();
        fila.pop();

        forn(c,0,26){
            for(ll x: gvindo[u][c]){
                for(ll y: gindo[v][c]){
                    if(visitados[x][y]) continue;
                    visitados[x][y] = true;
                    fila.push({x,y});
                    ans++;
                    debug(ans);
                }
            }
        }
    }

    cout << ans << ln;
    return 0;
}