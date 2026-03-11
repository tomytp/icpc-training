#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void) 0
#else
    #define trace(x) (void) 0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v ": "; for (auto x : v) cout << x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 998244353;
const ll INV2 = (998244353+1)/2;



ll expec(ll a, ll b){
    if(a == 0 || b == 0) return 0;
    if(a == b) return 1;
    if((a+b)%2 == 1) return 2;
    if(a%2 == 0) return expec(a/2, b/2);

    if(a>b) swap(a, b);
    return (1+INV2*expec(2*a, b-a))%MOD;
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << expec(a, b) << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}