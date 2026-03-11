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

ll w, h; 
bool relevant(ll x, ll y) {
    if ((x == 0 || x == w) || (y == 0 || y == h)) return true;
    return false;
}

int main() {
    _;
    cin >> w >> h;
    ll n; cin >> n;
    set<p64> top, bot, left, right;
    forn(i, 0, n) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (!relevant(x1, y1) || !relevant(x2, y2)) continue;
        if (x1 == 0) {
            left.insert({y1, i});
        } else if (x1 == w) {
            right.insert({y1, i});
        } else if (y1 == 0) {
            bot.insert({x1, i});
        } else if (y1 == h) {
            top.insert({x1, i});
        }

        if (x2 == 0) {
            left.insert({y2, i});
        } else if (x2 == w) {
            right.insert({y2, i});
        } else if (y2 == 0) {
            bot.insert({x2, i});
        } else if (y2 == h) {
            top.insert({x2, i});
        }
    }
    
    set<ll> opened;
    stack<ll> open;
    for (auto e : bot) {
        if (!opened.count(e.second)) {
            opened.insert(e.second);
            open.push(e.second);
        } else {
            if (open.top() != e.second) {
                cout << "N\n";
                return 0;
            }
            open.pop();
        }
    }

    for (auto e : right) {
        if (!opened.count(e.second)) {
            opened.insert(e.second);
            open.push(e.second);
        } else {
            if (open.top() != e.second) {
                cout << "N\n";
                return 0;
            }
            open.pop();
        }
    }
    
    for (auto e = top.rbegin(); e != top.rend(); e++){
        if (!opened.count(e->second)) {
            opened.insert(e->second);
            open.push(e->second);
        } else {
            if (open.top() != e->second) {
                cout << "N\n";
                return 0;
            }
            open.pop();
        }
    }
    
    for (auto e = left.rbegin(); e != left.rend(); e++){
        if (!opened.count(e->second)) {
            opened.insert(e->second);
            open.push(e->second);
        } else {
            if (open.top() != e->second) {
                cout << "N\n";
                return 0;
            }
            open.pop();
        }
    }

    cout <<"Y\n";

    return 0;
}