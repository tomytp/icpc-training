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

void solve(){
    ll n, a; cin >> n >> a;
    a = 2*a;

    if(a < n-2){
        cout << "No" << ln;
        return;
    }

    cout << "Yes" << ln;

    if(n==3){
        cout << "0 0\n1 0\n1 " << a << ln;
        return;
    }

    if(n ==4){
        cout << "0 0\n1 0\n1 " << a/2 << "\n0 " << a/2 << ln;
        return;
    }
    vector<pair<ll,ll>> poly;
    poly.push_back({0, 1});
    for(ll i = 1; i <= (n-2)/2; i++){
        poly.push_back({i, (i+1)%2});
    }

    if(n%2 == 1) poly.push_back({(n-1)/2, 1});

    for(ll i = (n-2)/2; i > 0; i--){
        poly.push_back({i, (i+1)%2 + 1});
    }

    poly.push_back({1,1 + a - (n-3)});

    for(auto p : poly){
        cout << p.first << " " << p.second << ln;
    }
}

int main(){
    _; ll t; cin >> t;
    forn(i,0, t) solve();
    return 0;
}