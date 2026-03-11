#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

map<string, ll> ang = {
    {"N", 0},
    {"E", 90},
    {"S", 180},
    {"W", 270},
    {"NE", 45},
    {"SE", 135},
    {"SW", 225},
    {"NW", 315}    
};

long double conv(string& s){
    if (sz(s) <= 2) return ang[s];
    string db = "NN";
    db[0] = s[(sz(s)-2)];
    db[1] = s[(sz(s)-1)];
    long double st = ang[db];
    long double step = 45.0/2;
    char dir = 'N';

    if (db[0] == 'N') {
        if (db[1] == 'E') dir = 'E';
        else dir = 'N';
    } else {
        if (db[1] == 'E') dir = 'S';
        else dir = 'W';
    }
    for (ll i = sz(s)-3; i >= 0; i--){
        if (s[i] == dir) st += step;
        else st -= step;
        step /= 2;
    }
    return st;
}

int main() {
    _;
    string a, b; cin >> a >> b;
    long double x = fabs(conv(a) - conv(b));
    cout << fixed << setprecision(20) << min(x, 360 - x) << ln;
    return 0;
}