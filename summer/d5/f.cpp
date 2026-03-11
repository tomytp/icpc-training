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
    ll k, n, p;
    cin >> k >> p >> n;
    ll resp = 0;

    forn(x, max((n/k)-p-1, 0ll), n/k + 1){
        ll curr = k*x + (x%k)*(x%p);
        if(curr == n) resp++; 
    }

    cout << resp << ln;
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}