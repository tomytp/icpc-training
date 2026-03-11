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

// Disjoint Set Union (Union-Find)
//
// Supports find with path compression and union by size to maintain dynamic connectivity of disjoint sets.
//
// complexity: O(alpha(N)) amortized per op, O(N)

struct dsu {
    vector<ll> id, len;

    dsu(ll n) : id(n), len(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (len[a] < len[b]) swap(a, b);
        len[a] += len[b], id[b] = a;
    }
};



int main(){
    _;
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<p64>> g(n);

    v64 esp(n);
    v64 esp_idx(k);
    forn(i,0,k){
        ll x; cin >> x;
        x--;
        esp[x] = 1;
        esp_idx[i] = x;
    }    

    vector<pair<ll, p64>> edges(m);
    forn(i,0,m){
        ll a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        edges[i] = {w, {a,b}};
    }

    sort(edges.rbegin(), edges.rend());

    ll q; cin >> q;

    forn(i,0,q){
        ll w; cin >> w;

        dsu sdu(n);

        for(auto [curr_w,p] : edges){
            if(curr_w < w) break;
            sdu.uni(p.first, p.second);
        }

        map<ll, ll> mp;

        for(ll j : esp_idx){
            mp[sdu.find(j)]++;
        }

        ll resp = 0;
        for(auto [key, v] : mp) resp += escolhe2(v);
        cout << resp << ln;
    }
    

    return 0;
}