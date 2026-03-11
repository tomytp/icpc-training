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

ll best = INF;

bool check(ll day){
    if(day < 0) return false;
    best = min(best, day);
    return true;
}

int main() {
    _;
    ll n; 
    string s;
    cin >> s >> n;
    ll wd = w_to_d[s];

    forn(i,0,n){
        ll x; cin >> x;
        if(x == 0){
            ll day = 30;
            if((day + wd)%7 == 5) day ++;
            if((day + wd)%7 == 6) day ++;
            best = min(best, day);
            continue;
        }
        ll past = -x;
        ll day = (wd-x)%7;
        if(day < 0) day += 7;

        if(day == 5){
            past += 30;
            if(check(past)) continue;
            day = 0;
        }

        if(day == 6){
            past += 30;
            if(check(past)) continue;
            day = 1;
        }

        if(day == 1){
            past += 30;
            if(check(past)) continue;
            day = 3;
        }

        if(day == 3){
            past += 32;
            if(check(past)) continue;
            day = 0;
        }

        if(day == 2){
            past += 30;
            if(check(past)) continue;
            day = 4;
        }

        if(day == 4){
            past += 31;
            if(check(past)) continue;
            day = 0;
        }

        past = past%91;

        if(check(past)) continue;
        past+=30;
        if(check(past)) continue;
        past+=30;
        if(check(past)) continue;
        past+=31;
        if(check(past)) continue;        
    }

    cout << best << ln;
    return 0;
}