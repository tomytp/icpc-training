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

#define debugv(v) trace({cout << #v": "; for (auto u : v) cout<< u << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll testa_mais(v64& mais, v64& menos, multiset<ll>& s, ll n){
    ll x = *s.begin() - mais[0];
    debug(x);
    multiset<ll> curr_s;
    
    for(ll m : mais) curr_s.insert(m+x);
    for(ll m : menos) curr_s.insert(m-x);
    debugv(curr_s);
    if(s == curr_s) return x;
    return -1;
}

ll testa_menos(v64& mais, v64& menos, multiset<ll> s, ll n){
    ll x = menos[0] - *s.begin();
    multiset<ll> curr_s;
    debug(x);
    
    for(ll m : mais) curr_s.insert(m+x);
    for(ll m : menos) curr_s.insert(m-x);
    debugv(curr_s);
    if(s == curr_s) return x;
    return -1;
}

int main(){
    _;
    ll n; cin >> n;
    v64 xs(n);
    v64 g(n);
 
    forn(i,0,n) cin >> xs[i];
    forn(i,0,n) cin >> g[i];

    v64 l(n-1);
    
    forn(i,0,n-1){
        l[i] = xs[i+1] - xs[i];
    }

    v64 mais, menos;

    mais.push_back(0);
    
    ll curr = 0;
    forn(i,0,n-1){
        if(i&1){
            mais.push_back(l[i]-curr);
        }else{
            menos.push_back(l[i]-curr);
        }
        curr = l[i]-curr;
    }

    sort(mais.begin(), mais.end());
    sort(menos.begin(), menos.end());

    debugv(mais);
    debugv(menos);

    multiset<ll> s;
    forn(i,0,n) s.insert(g[i]);
    debugv(s);
    ll x = testa_mais(mais,menos, s, n);
    debug(x);
    if(x == -1){
        debug(x);
        x = testa_menos(mais,menos, s, n);
    }

    curr = 0;
    v64 resp;
    resp.push_back(x);
    forn(i,0,n-1){
        curr = l[i]-curr;
        if(i&1){
            resp.push_back(curr+x);        
        }else{
            resp.push_back(curr-x);  
        }
    }

    forn(i,0,n) cout << resp[i] << " ";; cout << ln;

    return 0;
}