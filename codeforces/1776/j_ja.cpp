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

vector<v64> graph;
vector<ll> color;
ll diam = 0, n, g;

void bfs(ll s){
    vector<ll> dist_no_flip(n, INF), dist_flip(n, INF);
    vector<bool> visited(n, false);
    queue<ll> fila;

    dist_no_flip[s] = 0;
    visited[s] = true;
    fila.push(s);

    while(!fila.empty()){
        ll u = fila.front();
        fila.pop();

        for(auto v : graph[u]){
            if(visited[v]) continue;
            if(color[u] == color[v]){
                if(dist_no_flip[v] > dist_no_flip[u] + 1){
                    dist_no_flip[v] = dist_no_flip[u] + 1;
                }
                if(dist_flip[v] > dist_flip[u] + 1){
                    dist_flip[v] = dist_flip[u] + 1;
                }
            } else {
                if(dist_no_flip[v] > dist_flip[u] + 1){
                    dist_no_flip[v] = dist_flip[u] + 1;
                }
                if(dist_no_flip[v] > dist_flip[u] + 1){
                    dist_no_flip[v] = dist_flip[u] + 1;
                }
            }

            visited[v] = true;
            fila.push(v);
        }
    }
}


int main(){
    _; ll m; cin >> n >> m >> g;
    graph.resize(n);
    color.resize(n);
    forn(i, 0, n) cin >> color[i];
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    forn(i, 0, n) bfs(i);

    return 0;
}
