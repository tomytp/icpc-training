#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ (void)0
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void dfs(ll u, vector<v64>& g, v64& parent, vector<bool>& visited, v64& h) {
    visited[u] = true;
    
    for(auto v : g[u]) {
        if (visited[v]) continue;

        parent[v] = u;
        h[v] = h[u] + 1;
        dfs(v, g, parent, visited, h);
    }
}

v64 path(ll a, ll b, v64& parent, v64& h) {
    v64 p1, p2;
    ll a_or = a;

    if (h[a] < h[b]) swap(a, b);

    while(h[a] > h[b]) {
        p1.push_back(a);
        a = parent[a];
    }

    if (a == b) {
        p1.push_back(a);
        if (p1[0] != a_or) reverse(p1.begin(), p1.end());
        return p1;
    }

    while (a != b && a != -1 && b != -1) {
        p1.push_back(a);
        p2.push_back(b);
        a = parent[a];
        b = parent[b];
    }

    if (a == -1 || b == -1) {
        return {};
    }

    p1.push_back(a);
    for (ll i = p2.size() - 1; i >= 0; i--) {
        p1.push_back(p2[i]);
    }

    debug(a_or);
    debug(p1[0]);
    if (p1[0] != a_or) reverse(p1.begin(), p1.end());
    debug(p1[0]);
    return p1;
}

int main(){
    _;
    ll n, m; cin >> n >> m;

    // 0->n-1 (Filmes) | n-> n+m-1 (Atores)
    vector<v64> g(n + m);
    forn(i, 0, n){
        ll count; cin >> count;
        forn(j, 0, count) {
            ll actor; cin >> actor; actor--;
            g[i].push_back(n + actor);
            g[n + actor].push_back(i);
        }
    }

    v64 parent(n+m, -1);
    vector<bool> visited(n+m);
    v64 h(n+m, 0);
    forn(i, 0, n + m) {
        if (!visited[i]) {
            dfs(i, g, parent, visited, h);
        }
    }

    ll q; cin >> q;
    forn(i, 0, q) {
        ll a, b; cin >> a >> b;
        a--; b--;
        auto p = path(n+a, n+b, parent, h);
        
        if (p.size() == 0) {
            cout << -1 << ln;
            continue;
        }

        cout << (p.size()+1) / 2 << ln;
        forn(j, 0, p.size()) {
            ll val = p[j];
            if (val >= n) val -= n;
            cout << val + 1<< " \n"[j==p.size()-1];
        }
    }
    return 0;
}