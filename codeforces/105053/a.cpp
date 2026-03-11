#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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

const ld INF = 4e18;

// Convex Hull Trick Dinamico
//
// para double, use INF = 1/.0, div(a, b) = a/b
// update(x) atualiza o ponto de intersecao da reta x
// overlap(x) verifica se a reta x sobrepoe a proxima
// add(a, b) adiciona reta da forma ax + b
// query(x) computa maximo de ax + b para entre as retas
//
// O(log(n)) amortizado por insercao
// O(log(n)) por query

struct Line {
    mutable ld a, b, p;
    bool operator<(const Line& o) const { return a < o.a; }
    bool operator<(ld x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
    ld div(ld a, ld b) { 
        return a / b;
    }
    
    void update(iterator x) {
        if (next(x) == end()) x->p = INF;
        else if (x->a == next(x)->a) x->p = x->b >= next(x)->b ? INF : -INF;
        else x->p = div(next(x)->b - x->b, x->a - next(x)->a);
    }

    bool overlap(iterator x) {
        update(x);
        if (next(x) == end()) return 0;
        if (x->a == next(x)->a) return x->b >= next(x)->b;
        return x->p >= next(x)->p;
    }
        
    void add(ld a, ld b) {
        auto x = insert({a, b, 0});
        while (overlap(x)) erase(next(x)), update(x);
        if (x != begin() and !overlap(prev(x))) x = prev(x), update(x);
        while (x != begin() and overlap(prev(x))) 
            x = prev(x), erase(next(x)), update(x);
    }
    
    ld query(ld x) {
        assert(!empty());
        auto l = *lower_bound(x);
#warning cuidado com overflow!
        return l.a * x + l.b;
    }
};

struct pt {
    ll x0, y0, vx, vy;
 
    pair<ld,ld> pos(ld t) {
        return {(ld)x0 + t*vx, (ld)y0 + t*vy};
    }
};

int main(){
    _;
    ll n; cin >> n;

    vector<pt> pts(n);
    CHT a, b, c, d;
    forn(i, 0, n) {
        ll x, y, vx, vy; cin >> x >> y >> vx >> vy;
        a.add(vx, x);
        b.add(-vx, -x);
        c.add(vy, y);
        d.add(-vy, -y);
        pts[i] = {x, y, vx, vy};
    }

    set<ld> tts;

    for (auto x : a) tts.insert(x.p);
    for (auto x : b) tts.insert(x.p);
    for (auto x : c) tts.insert(x.p);
    for (auto x : d) tts.insert(x.p);

    function<ld (ld)> rec = [&](ld t) {
        ld x0 = INF, x1 = -INF, y0 = INF, y1 = -INF;
        forn(i, 0, n) {
            auto p = pts[i].pos(t);
            x0 = min(x0, p.first);
            x1 = max(x1, p.first);
            y0 = min(y0, p.second);
            y1 = max(y1, p.second);
        }
        return (x1 - x0) * (y1 - y0);
    };

    ld bst = 4e18;
    tts.insert(0);
    for(auto t : tts) {
        if (t < 0) continue;
        debug(t);
        auto temp = rec(t);
        debug(temp);
        if (temp < bst) {
            bst = temp;
        }
    }

    cout << setprecision(15) << fixed << bst << ln;

    return 0;
}