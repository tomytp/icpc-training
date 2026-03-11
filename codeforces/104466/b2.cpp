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

struct pt{
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0): x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x != p.x) return x < p.x;
        return y<p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }
    pt operator + (const pt p) const {return pt(x+p.x, y+p.y);}
    pt operator - (const pt p) const {return pt(x-p.x, y-p.y);}
    ll operator ^ (const pt p) const {return x*(ll)p.y - y*(ll)p.x;}
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

struct line {
    pt p, q;
    pt id;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {id = indentificador();}

    pt indentificador(){
        pt v = p-q;
        ll d = gcd(v.x, v.y);
        v.x /= d;
        v.y /= d;

        if(v.x < 0){
            v.x *= -1;
            v.y *= -1;
        } if(v.x == 0 && v.y < 0){
            v.y *= -1;
        }
        return v;
    }
    bool operator<(const line& o) const {
        return id < o.id;
    }
};

ll sarea2(pt p, pt q, pt r){
    return (q-p)^(r-q);
}

bool in_line(line l, pt p){
    return sarea2(l.p, l.q, p) == 0;
}

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

int main(){
    _;
    ll n; cin >> n;
    vector<pt> v(n);
    forn(i, 0, n) cin >> v[i];

    cout << "impossible\n";
    
    return 0;
}