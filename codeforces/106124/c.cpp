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

map<string, ll> m1 {
    {"Mon", 0},
    {"Tue", 1},
    {"Wed", 2},
    {"Thu", 3},
    {"Fri", 4},
    {"Sat", 5},
    {"Sun", 6}
};

map<string, ll> m2 {
    {"Mon", 7},
    {"Tue", 8},
    {"Wed", 9},
    {"Thu", 10},
    {"Fri", 11},
    {"Sat", 12},
    {"Sun", 13}
};

vector<string> order = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

ll day = 60*24;

ll tod(string s) {
    ll hour = 10*(s[0] - '0') + (s[1] - '0');
    ll minute = 10*(s[3] - '0') + (s[4] - '0');
    return hour * 60 + minute;
}

void fmt(ll t) {
    ll days = t/day;
    t %= day;
    ll hours = t/60;
    t %= 60;
    ll minutes = t;
    vector<pair<ll, string>> v;
    if (days) v.emplace_back(days, "day");
    if (hours) v.emplace_back(hours, "hour");
    if (minutes) v.emplace_back(minutes, "minute");
    if (sz(v) == 3) {
        cout << v[0].first << " " << v[0].second; 
        if (v[0].first != 1) cout << 's';
        cout << ", ";

        cout << v[1].first << " " << v[1].second; 
        if (v[1].first != 1) cout << 's';
        cout << ", ";

        cout << v[2].first << " " << v[2].second; 
        if (v[2].first != 1) cout << 's';
        cout << ln;
        return;
    }
    if (sz(v) == 2) {
        cout << v[0].first << " " << v[0].second; 
        if (v[0].first != 1) cout << 's';
        cout << " and ";

        cout << v[1].first << " " << v[1].second; 
        if (v[1].first != 1) cout << 's';
        cout << ln;
        return;
    }
    if(sz(v) == 1) {
        cout << v[0].first << " " << v[0].second; 
        if (v[0].first != 1) cout << 's';
        cout << ln;
    }

}

int main() {
    _;
    string d1, t1, d2, t2;
    cin >> d1 >> t1 >> d2 >> t2;

    ll idx1, idx2;
    forn (i, 0, sz(order)) {
        if (order[i] == d1) idx1 = i;
        if (order[i] == d2) idx2 = i;
    };

    ll time1 = tod(t1);
    ll time2 = tod(t2);

    if (idx1 == idx2) {
        // solve based on TOD
        if (time1 < time2) {
            debug(time1);
            debug(time2);
            fmt(time2 - time1);
        }else  {
            fmt(7*day - abs(time1-time2));
        }
        return 0;
    }

    if (idx1 < idx2) {
        ll days = m1[d2] - m1[d1] - 1;
        fmt((day-time1) + days*day + time2);
        // same week
        return 0;
    }

    //different week
    ll days = m2[d2] - m1[d1] - 1;
    fmt((day-time1) + days*day + time2);



    return 0;
}