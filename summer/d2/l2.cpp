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

void dfs(ll curr, ll parent, vector<v64>& g, v64& cores, ll cor_cara, ll q_cara, ll cor_barata,ll q_barata){
    bool root = (cores[curr] == -1);
    ll comp = sz(g[curr])+1;
    if(!root) comp--;

    ll baratas = min(q_barata, comp);
    ll caras = sz(g[curr])+1 - baratas;


    vector<p64> order;
    for(auto u : g[curr]) order.push_back({sz(g[u]) , u});

    sort(order.begin(), order.end());

    ll idx = 0;
    while(caras && (idx < sz(order) && )){
        idx++
    }

    for(auto u : g[curr]){
        if(u == parent) continue;
        dfs(u, curr, g, cores, cor_cara, q_cara, cor_barata, q_barata);
    }
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<v64> g(n);
    v64 cores(n, -1);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    map<ll, ll> cor;
    ll cor_cara, cor_barata, q_cara, q_barata; 
    forn(i, 0, n){
        ll a;
        cin >> a;
        cor[a]++;
    }

    if(sz(cor) == 1){
        auto it = cor.begin();
        cor_cara = it->first;
        cout << n*cor_cara << ln;
        return;
    }

    auto it = cor.begin();
    auto it2 = cor.rbegin();
    cor_barata = it->first;
    q_barata = it->first;
    cor_cara = it2->first;
    q_cara = it2->second;

    dfs(0, -1, g, cores, cor_cara, q_cara, cor_barata, q_barata);
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}