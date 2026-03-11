#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXP = 100;
const ll MAXCARD = 10;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main() {
    _; ll n = uniform(1, MAXCARD); cout << n << " ";
    ll p = uniform(0, MAXP); cout << p << " ";
    ll h = uniform(1,1000);
    cout << h << ln;
    
    vector<pair<char, ll>> vec;
    ll tot_sum = 0;
    ll tot_mult = 1;

    forn(i, 0, n){
        char c = "*!+"[uniform(0, 2)];
        ll val = uniform(1,10);
        vec.push_back({c,val});
        if(c == '+') tot_sum += val;
        if(c == '*') tot_mult *= val;
    }
    


    forn(i,0,n){
        cout << vec[i].first << " ";
        if(vec[i].first != '!'){
            cout << vec[i].second;
        }
        cout << ln;
    }
    return 0;
}