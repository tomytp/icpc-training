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

ll accpar(ll n){
    if(n < 0) return 0;
    return n/2 + 1;
}

void solve(){
    ll a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

    ll la = accpar(a2) - accpar(a1-1);
    ll lb = b2 - b1 + 1;
    ll lc = accpar(c2) - accpar(c1-1);
    
    cout << la*lb*lc << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t){
        cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}