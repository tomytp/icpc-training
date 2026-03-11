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
    ll n, s; cin >> n >> s;
    if(s < n-2){
        cout << "NO" << ln;
        return ;
    }

    cout << "YES" << ln;
    vector<pair<ll,ll>> v;

    if(n == 3){
        v.push_back({0,0});
        v.push_back({1,0});
        v.push_back({1,s});
    }

    else if(n == 4){
        v.push_back({0,1});
        v.push_back({2,0});
        v.push_back({1,1});
        v.push_back({1, s});
    }

    else {
        forn(i, 0, n/2){
            v.push_back({i, (i+1)%2});
        }
        if(n%2 == 1){
            v.push_back({(n/2), 1});
        }
        for(ll i = n/2-1; i>0; i--){
            v.push_back({i, (i+1)%2+1});
        }

        v.push_back({1, s - (n-3) + 1});
    } 

    for(auto p : v){
        cout << p.first << " " << p.second << ln;
    }
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}