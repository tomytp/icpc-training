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

struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ll c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*(ll)p.x+ y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y- y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
    return sarea2(p,q,r) > 0;
}

ll s;
vector<pt> v;

ll miguel(v64& a, v64& b){
    
}

ll solve(ll i, ll j){
    pt p1 = v[i], p2 = v[j];

    v64 a,b;
    forn(k, 0, v.size()){
        if(k == i || k == j) continue;
        if(ccw(p1, p2, v[k])) a.push_back(abs(sarea2(p1, p2, v[k])));
        else b.push_back(abs(sarea2(p1, p2, v[k])));
    }

    return miguel(a,b);
}

int main() {
    _; ll n; cin >> s >> n;
    s = 2*s;
    v.resize(n);
    forn(i, 0, n) cin >> v[i];

    ll ans = 0;
    forn(i, 0, n){
        forn(j, 0, n){
            ans += solve(i, j);
        }
    }

    cout << ans;
    return 0;
}