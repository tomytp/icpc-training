#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sz(x) ((ll) x.size())

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 1010;
const ll MAXV = 2'000'010;

struct pt {
    ll x, y;
    ll idx = -1;
    ll name = -1;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {
    }
    void build(){
        idx = x + 1002*(y+1);
    }
    bool operator < (const pt p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x && y == p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ll c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*p.x+y*p.y; }
    ll operator ^ (const pt p) const { return x*p.y - y*p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};

ll sarea2(pt p, pt q, pt r){
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r){
    return sarea2(p, q, r) >= 0;
}

ll polarea2(vector<pt> v) {
    ll ret = 0;
    for(int i = 0; i < v.size(); i++)
        ret += sarea2(pt(0,0), v[i], v[(i+1)%v.size()]);
    return abs(ret);
}

map<pair<ll,ll>,bool> visited;
vector<vector<ll>> grafo(MAXV);
vector<ll> name(MAXV, -1);
vector<pt> vert(MAXV);
ll n;

ll solve(ll u, ll v){
    if(visited[{u, v}]) return -1;
    vector<pt> poly;
    poly.push_back(vert[u]);

    ll curr = v, last = u, counter = 0;
    while(curr != u){
        poly.push_back(vert[curr]);
        visited[{last, curr}] = true;
        ll best = last;
        for(auto w : grafo[curr]){
            if(w == last) continue;
            if(ccw(vert[curr], vert[best], vert[w])) best = w;
        }
        last = curr;
        curr = best;
        counter ++;
    }

    return polarea2(poly);
}

int main() {
    _; ll e; cin >> e;
    
    vector<ll> areas;
    
    ll counter = 0;
    forn(i, 0, e){
        pt a, b;
        cin >> a >> b;
        a.build();
        b.build();
        
        if(name[a.idx] == -1){
            name[a.idx] = counter;
            vert[name[a.idx]] = a;
            counter++;
        }
        if(name[b.idx] == -1){
            name[b.idx] = counter;
            vert[name[b.idx]] = b;
            counter++;
        }
        
        grafo[name[a.idx]].push_back(name[b.idx]);
        grafo[name[b.idx]].push_back(name[a.idx]);
        visited[{name[a.idx],name[b.idx]}] = false;
        visited[{name[b.idx],name[a.idx]}] = false;
    }
    n = counter;

    forn(u, 0, n){
        for(auto v : grafo[u]){
            debug(u);
            debug(v);
            ll area = solve(u, v);
            if(area != -1) areas.push_back(area);
        }
    }

    sort(areas.begin(), areas.end());

    if(sz(areas) == 0){
        cout << 1 << ln;
        return 0;
    }
    ll sum = 0;
    if(sz(areas) == 1){
        sum = areas[0];
        ld areamax = ((ld)sum)/4;
        cout << fixed << setprecision(20) << areamax;
        return 0;
    }

    forn(i, 0, sz(areas)-1){
        sum += areas[i]*areas[i];
    }

    ld areamax = ((ld)sum)/4;

    cout << fixed << setprecision(20) << areamax << ln;

    return 0;
}