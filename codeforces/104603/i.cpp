#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld DINF = 1e18;
const ld eps  = 1e-9;

ll cmp(ld x, ld y, ld tol = eps){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ld ld_min(ld a, ld b){
    if(cmp(a,b)>=0) return b;
    return a;
}

struct pt {
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}

    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator / (const ld c) const { return pt(x/c, y/c); }
    ld operator * (const pt p) const { return x*(ld)p.x + y*(ld)p.y; }
    ld operator ^ (const pt p) const { return x*(ld)p.y - y*(ld)p.x; }
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

ld sarea(pt p, pt q, pt r){
    return ((q-p)^(r-q))/2;
}

ld dist(pt p, pt q){
    return sqrt((ld)(p.x-q.x)*(p.x-q.x) + (ld)(p.y-q.y)*(p.y-q.y));
}

pt rot90(pt p){
    return pt(p.y, -p.x);
}

ld dist_line(pt l_p, pt l_q, pt p){
    ld h = 2*abs(sarea(l_q, l_p, p))/dist(l_p, l_q);
    ld d = ld_min(dist(l_p, p), dist(l_q,p));

    if((p-l_p)*(l_q-l_p) >= 0 && (p-l_q)*(l_p-l_q) >= 0) return h;
    return d;
}

ld dist_poly(vector<pt> p1, vector<pt> p2){
    ld best = DINF;
    forn(i, 0, sz(p1))
    forn(j, 0, sz(p2)){
        best = ld_min(best, dist_line(p2[j], p2[(j+1)%sz(p2)], p1[i]));
        best = ld_min(best, dist_line(p1[i], p1[(i+1)%sz(p1)], p2[j]));
    }

    return best;
}

ld dist_circ(pair<pt, ld> circ, vector<pt> poly){
    ld best = DINF;
    forn(i, 0, sz(poly)){
        best = ld_min(best, dist_line(poly[i], poly[(i+1)%sz(poly)], circ.first));
    }

    return best - circ.second;
}

ld dist_tri_qua(vector<pt>& tri, vector<pt>& qua){
    return dist_poly(tri, qua);
}

ld dist_tri_cir(vector<pt>& tri, pair<pt, ld> cir){
    return dist_circ(cir, tri);
}

ld dist_qua_cir(vector<pt>& qua, pair<pt, ld> cir){
    return dist_circ(cir, qua);;
}

ld dist_cir_cir( pair<pt, ld> cir1,  pair<pt, ld> cir2){
    return dist(cir1.first, cir2.first) - cir1.second - cir2.second;
}

void dij(ll s, vector<ld>& d, vector<vector<pair<ll, ld>>>& g){
    ll n = sz(g);
    d.assign(n, DINF);

    d[s] = 0;
    priority_queue<pair<ld, ll>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        ll u = pq.top().second;
        ld d_u = -pq.top().first;
        pq.pop();

        if(cmp(d_u, d[u]) != 0) continue;

        for(auto edge : g[u]){
            ll v = edge.first;
            ld w_v = edge.second;
            if(cmp(d[u] + w_v, d[v]) < 0){
                d[v] = d[u] + w_v;
                pq.push({-d[v], v});
            }
        }
    }
}

void le_cir(pair<pt, ll>& c){
    ll x,y,r;
    cin >> x >> y >> r;
    c.first.x = x;
    c.first.y = y;
    c.second = r;
}

void le_tri(vector<pt>& tri){
    forn(j,0,3){
        ll x, y;
        cin >> x >> y;
        tri[j].x = x;
        tri[j].y = y;
    }
}

void le_qua(vector<pt>& qua){
    pt p, q;
    cin >> p >> q;
    pt m = (p+q)/2;
    pt r = rot90(q-m);
    qua = {p, m+r, q, m-r};
}

int main() {
    _;

    ll c,q,t;
    cin >> c >> q >> t;

    vector<vector<pt>> tri(t, vector<pt>(3));
    vector<vector<pt>> qua(q, vector<pt>(4));
    vector<pair<pt, ll>> cir(c);

    forn(i,0,c) le_cir(cir[i]);
    forn(i,0,q) le_qua(qua[i]);
    forn(i,0,t) le_tri(tri[i]);

    // 0, 1, ... t-1 tri
    // t, t+1, t... t + c-1 cir
    // t+c, t+c+1 ... t + c + q-1 qua
    // source = t+c+q

    ll n = c+q+t+1;
    ll src = c+q+t;

    vector<vector<pair<ll, ld>>> g(n);

    forn(i,0,t){
        forn(j,0,c){
            g[i].push_back({t+j, dist_tri_cir(tri[i], cir[j])});
        }
    }

    forn(i,0,c){
        forn(j,i+1,c){
            ld d = dist_cir_cir(cir[i], cir[j]);
            g[t+i].push_back({t+j, d});
            g[t+j].push_back({t+i, d});
        }
    }

    forn(i,0,c){
        forn(j,0,q){
            g[t+i].push_back({t+c+j, dist_qua_cir(qua[j], cir[i])});
        }
    }

    forn(i,0,t){
        forn(j,0,q){
            g[i].push_back({t+c+j, dist_tri_qua(tri[i], qua[j])});
        }
    }

    forn(i,0,t) g[src].push_back({i, 0});

    forn(i,0,sz(g)){
        debug(i);
        debugm(g[i]);
    }
    
    vector<ld> d;

    dij(src, d, g);

    ld resp = DINF;
    forn(i,0,q){
        resp = min(resp, d[t+c+i]);
    }
    cout << fixed << setprecision(20) << resp << ln;
    return 0;
} 