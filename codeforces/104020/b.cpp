#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld eps = 1e-21;
const ld pi = 2*acos(0);

ll cmp(ld x, ld y = 0, ld tol = eps) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct pt{
    ll x, y; 
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    bool operator == (const pt p) const {
        return x == p.x && y == p.y;
    }
    pt operator - (const pt p) const { return pt(x - p.x, y - p.y); }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }

    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
    return sarea2(p,q,r) > 0;
}

ld angle(pt v){
    ld ang = atan2(v.y, v.x);
    return ang;
}

vector<pt> convex_hull(vector<pt> &v) {
    v.erase(unique(v.begin(), v.end()), v.end());
    if(sz(v) <=1) return v;
    vector<pt> l, u;
    forn(i, 0, sz(v)) {
        while(sz(l) > 1 && !ccw(l.end()[-2], l.end()[-1], v[i]))
            l.pop_back();
        l.push_back(v[i]);
    }
    for(ll i = sz(v)-1; i>=0; i--) {
        while(sz(u) > 1 && !ccw(u.end()[-2], u.end()[-1], v[i]))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back();
    u.pop_back();
    for(pt i : u) l.push_back(i);
    return l;
}

ld calc(pt p, pt q){ 
    pt r = p-q;
    if(r.x < 0){
        r.x *= -1;
        r.y *= -1;
    }
    ld ang = angle(p-q);
    ang = abs(ang)*(ld)180/pi;
    if(cmp(ang,180) == 0) ang = 0;

    return ang;
}

int main() {
    _; ll n; cin >> n;
    vector<pt> v(n);
    forn(i, 0, n) cin >> v[i];

    trace(
    forn(i, 0, n) cout << v[i].x << " " << v[i].y << ln;
    );

    v = convex_hull(v);
    v.push_back(v[0]);
    n = sz(v);

    trace(
    forn(i, 0, n) cout << v[i].x << " " << v[i].y << ln;
    );


    ld best_ang = 0;
    forn(i, 1, n) {
        trace(
            cout << fixed << setprecision(20) << calc(v[i-1], v[i]) << ln;
        );
        best_ang = max(best_ang, calc(v[i-1], v[i]));
    }
    cout << fixed << setprecision(20) << best_ang << ln;

    return 0;
}