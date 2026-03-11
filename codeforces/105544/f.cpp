#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct frac{
    ll num, den;
    frac(ll num_ = 0, ll den_ = 1) : num(num_), den(den_){}

    friend bool operator < (const frac& l, const frac& r) {
        return l.num*r.den < r.num*l.den;
    }
};

void solve(){
    ll n; cin >> n;
    set<pair<frac, ll>> s;
    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        s.insert({frac(a,b), i});
    }
    for(auto x : s) cout << x.second+1 << " ";
    cout << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}