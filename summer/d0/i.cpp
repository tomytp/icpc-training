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

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld DINF = 1e18;
const ld eps = 1e-9;
const ld tol = 1e-7;

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { // r inter s
	if (eq((r.p - r.q) ^ (s.p - s.q), 0)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

vector<pt> poly;
ll n;

ld test(ld x){
    vector<pt> cut;
    line vert = line(pt(x, -DINF), pt(x, DINF));
    
    forn(i, 0, n) {
        pt a = poly[i];
        pt b = poly[(i+1)%n];
        line l(a, b);
        
        bool a_left = a.x < x + eps;
        bool b_left = b.x < x + eps;
        
        if(a_left && b_left){
            cut.push_back(b);
        }
        else if(a_left && !b_left){
            cut.push_back(inter(l, vert));
        }
        else if(!a_left && b_left){
            cut.push_back(inter(l, vert));
            cut.push_back(b);
        }
    }
    
    if(cut.empty()) return 0;
    return polarea(cut);
}


int main(){
    _; ll k; cin >> n >> k;
    poly.resize(n);
    ll min_x = INF;
    ld max_x = -INF;

    forn(i, 0, n){
        ll a, b; cin >> a >> b;
        poly[i] = pt(a,b);
    }

    ld s = polarea(poly);

    ld target = s/(k+1);

    ll it = 300;
    ld l = min_x, r = max_x, m;
    forn(i, 0, it){
        m = (l+r)/2;

        ld ans = test(m);

        if(ans < target){
            l = m;
        } else {
            r = m;
        }
    }

    cout << fixed << setprecision(10) << (l+r)/2 << ln;

    return 0;
}