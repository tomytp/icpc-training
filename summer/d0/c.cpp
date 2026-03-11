#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// Disjoint Set Union (Union-Find)
//
// Supports find with path compression and union by size to maintain dynamic connectivity of disjoint sets.
//
// complexity: O(alpha(N)) amortized per op, O(N)

ll escolhe2(ll a){ return (a*(a-1))/2;}

struct dsu {
    vector<ll> id, len, lenk;
    ll resp = 0;

    dsu(ll n, v64 esp) : id(n), len(n, 1), lenk(esp) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (len[a] < len[b]) swap(a, b);
        len[a] += len[b], id[b] = a;
        resp -= escolhe2(lenk[a]);
        resp -= escolhe2(lenk[b]);
        lenk[a] += lenk[b];
        resp += escolhe2(lenk[a]);
    }
};


int main(){
    _;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<p64>> g(n);

    v64 esp(n);
    forn(i,0,k){
        ll x; cin >> x;
        x--;
        esp[x] = 1;
    }    

    ll maxw = 0;
    vector<pair<ll, p64>> edges(m);
    forn(i,0,m){
        ll a, b, w;
        cin >> a >> b >> w;
        maxw = max(maxw,w);
        a--, b--;
        edges[i] = {w, {a,b}};
    }

    sort(edges.rbegin(), edges.rend());

    ll q; cin >> q;
    vector<p64> queries(q);
    forn(i,0,q){
        ll x; cin >> x;
        queries[i] = {x, i}; 
    }
    
    sort(queries.rbegin(), queries.rend());

    ll p1 = 0;
    v64 ans(q);

    dsu sdu(n, esp);

    
    while(p1 < q && queries[p1].first > maxw){
        ans[queries[p1].second] = 0;
        p1++;
    }
    
    ll idx = 0;
    while(idx < m){
        ll curr_w = edges[idx].first;

        while(p1 < q && queries[p1].first > curr_w){
            trace(cout << "q: " << queries[p1].first << ln;);
            ans[queries[p1].second] = sdu.resp;
            p1++;
        }

        while(idx < m && edges[idx].first == curr_w){
            ll a = edges[idx].second.first;
            ll b = edges[idx].second.second; 
            trace(cout << "E: " << a << " " << b << " " << curr_w << ln;);
            sdu.uni(a,b);
            idx++;
        }

    }

    while(p1 < q){
        ans[queries[p1].second] = sdu.resp;
        p1++;
    } 
 
    forn(j,0,q) cout << ans[j] << ln;
    return 0;
} 