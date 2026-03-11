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

struct LCA{
    vector<v64>& g;
    ll n, lg, timer = 0;
    v64 tin, tout, h;
    vector<v64> up;

    LCA(vector<v64>& g_,ll root=0)
        : g(g_), n(g_.size()), lg(__lg(n)+1),
          tin(n), tout(n),h(n), up(lg, v64(n)) {dfs(root,root); h[root] = 0;}

    ll lca(ll a,ll b) {
        if(anc(a,b)) return a;
        if(anc(b,a)) return b;
        for(ll k=lg-1;k>=0;--k)
            if(!anc(up[k][a],b)) a = up[k][a];
        return up[0][a];
    }

    ll danc(ll u, ll ancu){
        return h[u] - h[ancu] ;
    }

    ll dist(ll a, ll b) {
        ll lc = lca(a, b);
        return danc(a, lc) + danc(b, lc);
    }

    void dfs(ll v,ll p){
        if(v != p) h[v] = h[p]+1;
        tin[v]=timer++; up[0][v]=p;
        for(ll k=1;k<lg;++k) up[k][v]=up[k-1][ up[k-1][v] ];
        for(ll to:g[v]) if(to!=p) dfs(to,v);
        tout[v]=timer++;
    }
    bool anc(ll a,ll b) {
        return tin[a]<=tin[b] && tout[a]>=tout[b];
    }
};


int main(){
    _;
    ll n, q; cin >> n >> q;
    vector<v64> g(n);

    forn(i,0,n-1){
        ll u, v;
        cin >> u >> v;
        u--; v--;   
        g[u].push_back(v);
        g[v].push_back(u);
    }  

    LCA lca(g, 0);

    forn(i,0,q){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        ll d1 = lca.dist(a, b);
        ll d2 = lca.dist(c, d);
        ll d3 = lca.dist(a, c);
        ll d4 = lca.dist(b, d);
        ll resp = 0;

        ll resp1 = d1 + d2 - d3 - d4;
        ll resp2 = d1 + d2 - lca.dist(a, d) -lca.dist(b, c);
        
        if (resp1 < 0 && resp2 < 0) {
            cout << 0 << ln;
            continue;
        }
        resp = max(resp1, resp2);
        resp = (resp/2) + 1;
        cout << resp << ln;
    }

    return 0;
}