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

ll calc(ll x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    return stoi(s);
}

int main(){
    _;

    ll MAX = 1'000'005;
    ll sum = 0;
    ll pot = 1;
    set<ll> pode;
    forn(i,0,10) {
        pode.insert(pot);
        pot *= 10;
    }

    forn(i,1,MAX){
        sum += calc(i);
        if(pode.count(i)) cout << i << " " << sum << ln;
    }
    return 0;
}