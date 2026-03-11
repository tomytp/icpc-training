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

ll wd;

ll adjust(ll day){
    if((day+wd)%7 == 5) day++;
    if((day+wd)%7 == 6) day++;
    return day;
}

int main() {
    _;
    ll n; 
    string s;
    cin >> s >> n;
    wd = w_to_d[s];

    ll best = INF;
    forn(i,0,n){
        ll x; cin >> x;
        if(x == 0) best = min(best, adjust(30));
        else{
            ll next = (-x)%30;
            if(next!=0)next+=30;
            best = min(best, adjust(next));
        }
    }

    cout << best << ln;
    return 0;
}