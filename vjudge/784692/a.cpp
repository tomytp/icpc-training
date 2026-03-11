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

ll accxor(ll k){
    if(k < 0) return 0;
    ll lb = 4*(k/4);
    ll x = 0;
    forn(i,lb,k+1) x ^= i;
    return x;
}

int main(){
    _;

    ll n; cin >> n;

    ll resp = 0;

    forn(i,0,n){
        ll x, m;
        cin >> x >> m;
        ll curr = accxor(x-1)^accxor(x+m-1);
        resp ^= curr;
    }   

    if(resp){
        cout << "tolik" << ln;
    }else{
        cout << "bolik" << ln;
    }
    return 0;
}