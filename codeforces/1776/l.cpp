#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll p, m;

void solve(){
    ll a, b; cin >> a >> b;

    if(a==b){
        if(m == p)cout << "YES" << ln;
        else cout << "NO" << ln;
        return;
    }

    if(b*(m-p)%(a-b) != 0){
        cout << "NO" << ln;
        return;
    }

    ll x = b*(m-p)/(a-b);

    if(-m <= x and x <= p){
        cout << "YES" << ln;
    }
    else cout << "NO" << ln;
}

int main(){
    _; ll n; cin >> n;
    forn(i, 0, n){
        char c; cin >> c;
        if(c == '+') p++;
        else m++;
    }

    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}
