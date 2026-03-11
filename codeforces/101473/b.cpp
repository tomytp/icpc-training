#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXX = 1000008;

struct pt {
    ll x, y, volta;
    pt(ll x_=0, ll y_=0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }

    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }

    pt operator - (const pt p) const {return pt(x-p.x, y -p.y);}
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }

    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

struct line {
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
};

ll sarea2(pt p, pt q, pt r){
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r){
    return sarea2(p, q, r) > 0;
}

struct sweepline {
    bool operator() (const line& a, const line& b) const {
        if(a.p == b.p) return ccw(a.p, a.q, b.q);
        if(a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x)) return ccw(a.p, a.q, b.p);
        return ccw(a.p,b.q,b.p);
    }
};

struct sweep {
    v64 beg, fim, query;
};

map<pt, ll> volta;

struct dsu {
    vector<ll> id, len, x, y;

    dsu(ll n) : id(n), len(n, 1), x(n), y(n) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (len[a] < len[b]) swap(a, b);
        len[a] += len[b];
        id[b] = a;
        if(y[a] <  y[b]){
            y[a] = y[b];
            x[a] = x[b];
        } 
    }

    void print(){
        for(ll s: id) cout << s << " ";; cout << ln;
        for(ll s: id) cout << x[find(s)] << " ";; cout << ln;
        for(ll s: id) cout << y[find(s)] << " ";; cout << ln;
        cout << ln;
    }

    void set_y(ll a, ll y_){ 
        y[find(a)] = y_;
    }
};

bool ind1(set<line, sweepline>& active, ll& y_final, ll& indice){
    if(active.empty()){
        y_final = INF;
        return true;
    }

    line l = *active.begin();
    if(l.p.y == l.q.y){
        y_final = l.p.y;
        return true;
    }
 
    // trace(
    //     cout << l.p.x << " " << l.p.y << " " << l.p.volta << ln;
    //     cout << l.q.x << " " << l.q.y << " " << l.q.volta << ln;
    // );

    if(l.p.y > l.q.y){
        indice = l.p.volta;
    }
    else{
        indice = l.q.volta;
    }

    return false;
}

bool ind_fecha(set<line, sweepline>& active, ll& y_final, ll& indice, line l){
    if(l.p.y == l.q.y){
        y_final = l.p.y;
        return true;
    }

    if(l.p.y > l.q.y){
        indice = l.p.volta;
        return false;
    }

    auto it = active.find(l);
    if(it == prev(active.end())){
        y_final = INF;
        return true;
    }

    it++;
    auto l2 = *it;   
    
    if(l2.p.y == l2.q.y){
        y_final = l2.p.y;
        return true;
    }

    if(l2.p.y > l2.q.y){
        indice = l2.p.volta;
    }
    else{
        indice = l2.q.volta;
    }
    return false;
}

bool ind_abre(set<line, sweepline>& active, ll& y_final, ll& indice, line l){
    if(l.p.y == l.q.y){
        y_final = l.p.y;
        return true;
    }

    if(l.p.y < l.q.y){
        indice = l.q.volta;
        return false;
    }

    auto it = active.find(l);
    if(it == prev(active.end())){
        y_final = INF;
        return true;
    }

    it++;
    auto l2 = *it;   
    
    if(l2.p.y == l2.q.y){
        y_final = l2.p.y;
        return true;
    }

    if(l2.p.y > l2.q.y){
        indice = l2.p.volta;
    }
    else{
        indice = l2.q.volta;
    }
    return false; 
}

int main() {
    _; ll n, q; cin >> n >> q; 
    
    dsu sdu(2*n+q);
    vector<line> v(n);
    vector<sweep> sl(MAXX);
    
    ll cnt = q;

    forn(i, 0, n){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > c){
            swap(a, c);
            swap(b, d);
        }

        v[i] = line(pt(a, b), pt(c, d));
        sl[a].beg.push_back(i);
        sl[c].fim.push_back(i);

        sdu.x[cnt] = v[i].p.x;
        sdu.y[cnt] = v[i].p.y;

        v[i].p.volta = cnt; 
        
        cnt++;

        sdu.x[cnt] = v[i].q.x;
        sdu.y[cnt] = v[i].q.y;
        
        v[i].q.volta = cnt; 
        
        cnt++;
    }

    forn(i, 0, q){
        ll a; cin >> a;
        sl[a].query.push_back(i);
        volta[pt(a,0)] = i;

        sdu.x[i] = a;
        sdu.y[i] = 0;
    }


    set<line, sweepline> active;
    forn(i, 0, MAXX){
        trace(
            if(i > 11){
                cout << "TIRA ISSO ANIMAL" << ln;
                break;
            }

            debug(i);
            for(ll aux : sl[i].query) cout << aux << " ";; cout << ln;
            for(ll aux : sl[i].beg) cout << aux << " ";; cout << ln;
            for(ll aux : sl[i].fim) cout << aux << " ";; cout << ln;
            sdu.print();
        );
        

        for(auto idx : sl[i].beg){
            line l = v[idx];
            ll y_max, indice;
            active.insert(l);
            bool goes_up = ind_abre(active, y_max, indice, l);

            if(goes_up){
                sdu.set_y(l.p.volta,y_max);
            }
            else{
                sdu.uni(l.p.volta, indice);
            }
        }


        for(auto idx : sl[i].query){
            ll y_max, indice;
            bool goes_up = ind1(active, y_max, indice);
            debug(goes_up);
            if(goes_up){
                sdu.set_y(idx,y_max);
            }
            else{
                sdu.uni(idx, indice);
            }
        }

        for(auto idx : sl[i].fim){
            line l = v[idx];
            ll y_max, indice;
            bool goes_up = ind_fecha(active, y_max, indice, l);
            active.erase(l);

            if(goes_up){
                sdu.set_y(l.q.volta,y_max);
            }
            else{
                sdu.uni(l.q.volta, indice);
            }
        }
        
    }

    forn(i,0,q){
        ll x = sdu.x[sdu.find(i)];
        ll y = sdu.y[sdu.find(i)];
        if(y >= INF){
            cout << x << ln;
        }else{
            cout << x << " " << y << ln;
        }
    }

    return 0;
}