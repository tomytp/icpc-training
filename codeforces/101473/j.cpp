#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debugm(v) trace({cout << #v": "; for (auto x : v) cout<< x.first << ":" << x.second << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll LOG = 20;

struct dsu {
    vector<ll> id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (len[a] < len[b]) swap(a, b);
        len[a] += len[b];
        id[b] = a;
    }
};

struct st {
    ll a, b, c;
    bool operator<(st o) {
        if (c != o.c) return c < o.c;
        if (b != o.b) return b < o.b;
        if (a != o.a) return a < o.a;
        return false;
    }
};

int main() {
    _;
    ll n, m, s; cin  >> n >> m >> s;
    vector<st> edg(m);
    for (auto& [a, b, c] : edg) {
        cin >> a >> b >> c;
        a--; b--;
    }
    sort(edg.rbegin(), edg.rend());
    dsu sdu(n);

    vector<vector<p64>> g(n);


    forn(i, 0, m) {
        if (sdu.find(edg[i].a) == sdu.find(edg[i].b)) continue;
        g[edg[i].a].emplace_back(edg[i].b, edg[i].c);
        g[edg[i].b].emplace_back(edg[i].a, edg[i].c);
        sdu.uni(edg[i].a, edg[i].b);
    }
    
    v64 h(n);
    vector<vector<p64>> bl(LOG, vector<p64>(n));
    
    function<void (ll, ll, ll)> dfs = [&](ll u, ll p, ll wp){
        if(p == -1){
            h[u] = 0;
            bl[0][0] = {0, INF};
        }else{
            h[u] = h[p]+1;
            bl[0][u] = {p, wp};
        }

        for(auto [v,wv]: g[u]) if(v != p){ 
            dfs(v,u, wv);
        }
    };

    dfs(0, -1, 0);

    forn(j,1,LOG){
        forn(i,0,n){
            ll pai = -1;
            ll peso = 0;
            pai = bl[j-1][bl[j-1][i].first].first;
            peso = min(bl[j-1][i].second, bl[j-1][bl[j-1][i].first].second);
            bl[j][i] = {pai, peso};
        }
    } 

    forn(i,0,4){
        debugm(bl[i]);
    }

    forn(aaa, 0, s) {
        ll a, b; cin >> a >> b;
        a--, b--;
        if(h[a] < h[b]) swap(a,b);
        ll resp = INF;

        debug(a);
        debug(b);
        for(ll i = LOG-1; i >= 0; i--){
            ll pot = 1<<i;
            if(h[a]-pot < h[b]) continue;
            auto [p, w] = bl[i][a];
            a = p;
            resp = min(resp, w);
        }
        
        if(a == b){
            cout << resp << ln;
            continue;
        };
        
        debug(a);
        debug(b);
        for(ll i = LOG-1; i >= 0; i--){
            if(bl[i][a].first == bl[i][b].first) continue;
            auto [pa, wa] = bl[i][a];
            auto [pb, wb] = bl[i][b];
            a = pa;
            b = pb; 
            trace(
                cout << i << ln;
                cout << pa << " " << pb << ln;
                cout << wa << " " << wb << ln;
            );
            resp = min(resp, min(wa,wb));
        }

        resp = min(resp, min(bl[0][a].second, bl[0][b].second));
        cout << resp << ln;
    }

    return 0;
}