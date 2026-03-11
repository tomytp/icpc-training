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

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<v64> gout(n);
    vector<v64> gin(n);

    forn(i,0,m){
        ll a, b; cin >>a >> b;
        a--, b--;
        gout[a].push_back(b);
        gin[b].push_back(a);
    }

    p64 best = {-1ll,-1ll}; 
    
    forn(i,0,n){
        set<ll> s;
        for(ll x: gin[i]) s.insert(x);
        for(ll x: gout[i]) if(s.count(x)){
            s.erase(x);
        } 

        debug(sz(s));
        if(sz(s) > best.first){
            best.first = sz(s);
            best.second = i;
        }
    }
    
    cout << best.second+1 << " " << best.first << ln;
}