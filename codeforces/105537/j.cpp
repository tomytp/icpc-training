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

void solve(){
    ll n, m; cin >> n >> m;
    vector<ll> delta(n, 0), ord;
    vector<vector<ll>> graph(n), anti_graph(n);
    vector<bool> visited(n, false);

    forn(i, 0, m){
        ll a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        anti_graph[b].push_back(a);
        delta[b]++;
        delta[a]--;
    }

    priority_queue<pair<ll,ll>> pq;
    forn(i, 0, n) pq.push({-delta[i], i});

    while(!pq.empty()){
        auto [d, curr] = pq.top();
        pq.pop();

        d = -d;
        if(d != delta[curr]) continue;
        if(visited[curr]) continue;

        ord.push_back(curr);
        visited[curr] = true;

        for(auto v : graph[curr]){
            if(visited[v]) continue;
            delta[v]--;
            pq.push({-delta[v], v});
        }

        for(auto v : anti_graph[curr]){
            if(visited[v]) continue;
            delta[v]++;
            pq.push({-delta[v], v});
        }
    }

    for(auto x : ord) cout << x+1 << " ";
    cout << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i,0,t) solve();
    return 0;
}