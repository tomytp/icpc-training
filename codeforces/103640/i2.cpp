#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

map<string, ll> w_to_d = {
    {"Mon", 0},
    {"Tue", 1},
    {"Wed", 2},
    {"Thu", 3},
    {"Fri", 4},
    {"Sat", 5},
    {"Sun", 6},
};

int main() {
    _;
    ll n; 
    string s;
    cin >> s >> n;
    ll wd = w_to_d[s];

    ll dmax = 0;
    forn(i,0,n){
        ll x; cin >> x;
        if(x == 0) continue;
        x = x%30;
        if(x == 0) x = 30; 
        dmax = max(x, dmax);
    }

    ll faltam = 30 - dmax; 
    
    debug(faltam);
    debug(wd);

    if( (faltam + wd)%7 == 6){
        faltam += 1;
    }else if((faltam + wd)%7 == 5){
        faltam += 2;
    }

    cout << faltam << ln;
    return 0;
}