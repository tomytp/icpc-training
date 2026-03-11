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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

map<ll,ll> mp;

ll find(ll n){
    if(mp[n]!= 0) return mp[n];
    ll pot = 1;
    while(2*pot + 1 <= n){
        pot = 2*pot + 1;
    }
    mp[n] = pot;
    return pot;
}

void solve(){
    ll n; cin >> n;
    ll op = -1;
    while(n>0){
        ll aux = find(n);
        n -= aux;
        op++;
    }

    cout << op << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();
    return 0;
}