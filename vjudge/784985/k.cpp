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

void solve(){
    ll n;
    cin >> n;
    set<ll> s;

    forn(i,0,n){
        ll x; cin >> x;
        s.insert(x);
    }

    n = sz(s);
    v64 vec(n);
    ll idx = 0;
    for(ll x: s) vec[idx++] = x;
    
    idx = 0; 
    ll ganha = 1;
    while(idx < n && vec[idx] == idx+1){
        ganha ^= 1;
        idx++;
    }  

    if(idx == n) ganha ^= 1;
    
    if(ganha){
        cout << "Alice" << ln;
    }else{
        cout << "Bob" << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
 
    return 0;
} 