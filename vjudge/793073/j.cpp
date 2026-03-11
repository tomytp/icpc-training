#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
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

struct pt {
    ll x, y;
    bool operator<(pt o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
    pt operator+(pt o) const {
        return {x+o.x, y+o.y};
    }
    bool operator==(pt o) const {
        return x == o.x && y == o.y;
    }
};

vector<pt> v;
set<pt> st;

vector<pt> moves;
pt mleft = {-1, 0};
pt mright = {+1, 0};
pt mup = {0, +1};
pt mdown = {0, -1};
pt me;

void move(pt p, pt dir, bool start = true) {
    if (start) {
        moves.push_back(dir);
    }
    if (st.count(p+dir)) {
        move(p+dir, dir, false);
    }

    if (start) {
        me = me + dir;
    } else {
        st.erase(p);
        if (!(p+dir == (pt){0, 0})) {
            st.insert(p+dir);
            *find(v.begin(), v.end(), p) = p+dir;
        } else {
            v.erase(find(v.begin(), v.end(), p));
        }
    }
}

void solve() {
    auto tg = v.back();
    if (me.x == tg.x) move(me, mright);
    if (me.y == tg.y) move(me, mup);
    
    if (tg.x > 0) {
        while (me.x <= tg.x) move(me, mright);
        while (me.y < tg.y) move(me, mup);
        while (me.y > tg.y) move(me, mdown);
        while (me.x > 1) move(me, mleft);
        
        if (me.y > 0) {
            move(me, mup);
            move(me, mleft);
            while (me.y > 1) move(me, mdown);
        }
        if (me.y < 0) {
            move(me, mdown);
            move(me, mleft);
            while (me.y < -1) move(me, mup);
        }
    } else {
        while (me.x >= tg.x) move(me, mleft);
        while (me.y < tg.y) move(me, mup);
        while (me.y > tg.y) move(me, mdown);
        while (me.x < -1) move(me, mright);
        
        if (me.y > 0) {
            move(me, mup);
            move(me, mright);
            while (me.y > 1) move(me, mdown);
        }
        if (me.y < 0) {
            move(me, mdown);
            move(me, mright);
            while (me.y < -1) move(me, mup);
        }
    }
}

int main() {
    _;
    ll n; cin >> n;
    pt tg;
    cin >> me.x >> me.y >> tg.x >> tg.y;
    me.x -= tg.x;
    me.y -= tg.y;

    v.resize(n);
    forn(i, 0, n) {
        cin >> v[i].x >> v[i].y;
        v[i].x -= tg.x;
        v[i].y -= tg.y;
        st.insert(v[i]);
    }

    while (sz(v)) {
        debug(sz(v));
        solve();
    }
    
    for (auto p : moves) {
        if (p.x > 0) cout << "right" << ln;
        if (p.x < 0) cout << "left" << ln;
        if (p.y > 0) cout << "up" << ln;
        if (p.y < 0) cout << "down" << ln;
    }
    return 0;
}
