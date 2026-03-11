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
    friend ostream& operator << (ostream& in, pt& p){
        return in << p.x << "," << p.y;
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

bool in_line_meu(line l, pt p){
    return sarea2(l.p, l.q, p) == 0;
}

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

line find(vector<pt>& v, ll thresh) {
    ll n = v.size();
    forn(i, 0, min(20ll, n)) {
        map<line, ll> mp;
        forn(j, i+1, n) {
            line l = line(v[i], v[j]);
            ll& va = mp[l]; 
            va++;
            if (va+1 >= thresh) return l;
        }
    }
    return line({INF, INF+1}, {INF, INF});
}

vector<pt> nv(vector<pt>& v, line l) {
    vector<pt> pts;
    for (auto x : v) {
        if (!in_line_meu(l, x)) pts.push_back(x);
    }
    return pts;
}

void solve10(ll n, vector<pt> v){
    forn(p1,0,n)
    forn(p2,p1+1,n)
    forn(p3,p2+1,n)
    forn(p4,p3+1,n){

        line l1(v[p1], v[p2]);
        line l2(v[p3], v[p4]); 

        auto v2 = nv(v, l1);
        auto v3 = nv(v2, l2);
        
        if(sz(v3) <= 2){
            cout << "possible" << ln;
            return; 
        }

        pt pt5 = v3[0];
        pt pt6 = v3[1];

        line l3(pt5, pt6);
        bool deu_ruim = false;
        forn(i, 0, n){
            if(!in_line_meu(l1, v[i]) && !in_line_meu(l2, v[i]) && !in_line_meu(l3, v[i])) deu_ruim = true;
        }
        
        if(!deu_ruim){
            cout << "possible" << ln;
            return; 
        }
    }
    
    cout << "impossible" << ln;
}

int main(){
    _;
    ll n; cin >> n;
    vector<pt> v(n);
    forn(i, 0, n) cin >> v[i];

    if (n <= 6) {
        cout << "possible\n";
        return 0;
    }

    if(n <= 20){
        solve10(n, v);
        return 0;
    }
    shuffle(v.begin(), v.end(), rng);
    
    debugv(v);
    line l1 = find(v, min(4ll, (n+2)/3));

    if (l1.p.x == INF) {
        cout << "impossible\n";
        return 0;
    }
    
    v = nv(v, l1);
    n = sz(v);
    debugv(v);
    
    if (n <= 4) {
        cout << "possible\n";
        return 0;
    }
    
    line l2 = find(v, 3);
    
    if (l2.p.x == INF) {
        cout << "impossible\n";
        return 0;
    }
    
    v = nv(v, l2);
    n = sz(v);
    debugv(v);

    if (n <= 2) {
        cout << "possible\n";
        return 0;
    }

    line l3(v.front(), v.back());

    for (auto x : v) {
        if (!in_line_meu(l3, x)) {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << "possible\n";
    return 0;
}