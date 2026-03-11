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

struct dsu {
    v64 id, size;
    dsu(ll n) : id(n), size(n,1) { iota(id.begin(), id.end(), 0);}

    ll find(ll a) {return a == id[a] ? a : id[a] = find(id[a]);};

    void uni(ll a, ll b){
        a = find(a), b = find(b);
        if(a == b) return; 
        if(size[a] < size[b]) swap(a,b);
        size[a] += size[b], id[b] = a;
    }

};

int main(){
    _;
    ll n, m, k; cin >> n >> m >> k;
    vector<v64> g(n);
    dsu sdu(n);

    forn(i,0,m){
        ll a, b; cin >>a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        sdu.uni(a,b);
    }

    v64 cor(n,1);
    v64 resp(n);
    bool bom = true;
    forn(i,0,n){
        ll p = sdu.find(i);
        if(sdu.size[p] < k) {bom = false; break;}
        debug(p);
        resp[i] = min(k, cor[p]++);
    }

    if(bom){
       forn(i,0,n) cout << resp[i] << " ";; cout << ln;
    }else{
        cout << "impossible" << ln;
    } 
}