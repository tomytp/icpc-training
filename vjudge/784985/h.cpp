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

v64 par;
v64 imp;

vector<v64> g;
v64 apples;

ll cor_folha = -1;

void dfs(ll u, ll p, ll cor){
    debug(u);
    if(cor == 0){
        par.push_back(apples[u]);
    }else{
        imp.push_back(apples[u]);
    }
    ll cnt = 0;

    for(ll v: g[u]) if(v != p){
        cnt++;
        dfs(v, u, cor^1);
    }

    if(cnt == 0){
        cor_folha = cor;
    }
}

int main(){
    _;
    ll n; cin >> n;

    g.resize(n);
    apples.resize(n);

    forn(i,0,n) cin >> apples[i];

    forn(i,1,n){
        ll p; cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }

    dfs(0, -1, 0);
    
    v64 pretas; 
    v64 brancas;
    if(cor_folha == 0){
        pretas = par;
        brancas = imp;
    }else{
        pretas = imp;
        brancas = par;
    }

    debugv(pretas);
    debugv(brancas);

    map<ll, ll> freq;
    ll accxor = 0;
    for(ll p : pretas){
        freq[p]++;
        accxor ^= p;
    }

    ll resp = 0;

    if(accxor == 0){
        resp += sz(brancas)*(sz(brancas)-1)/2;  
        resp += sz(pretas)*(sz(pretas)-1)/2;        
    }

    debug(resp);
    debug(accxor);

    for(ll b: brancas){
        ll guess = accxor^b;
        resp += freq[guess];
    }

    cout << resp << ln;
    return 0;
}