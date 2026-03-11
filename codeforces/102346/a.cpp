#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";
#define sq(x) ((x)*(ll)(x))

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif


const ll INF = 0x3f3f3f3f3f3f3f3fll;
vector<bool> visited;
ll k;
vector<v64> graph;
bool possible = true;

struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};
    
struct line {
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
};

ll dist2(pt p, pt q) {
    return sq(p.x - q.x) + sq(p.y - q.y);
}

struct circ{
    pt c;
    ll r;
    circ(){
        c = pt(0,0);
        r = 0;
    }
};

bool inter(circ c1, circ c2){
    return dist2(c1.c, c2.c) <= sq(c1.r + c2.r);
}

bool inter_line(circ c, line l){
    if(l.p.x == l.q.x){
        ll minx = c.c.x - c.r, maxx = c.c.x+c.r;
        return minx <= l.p.x and maxx >= l.p.x;
    }
    else{
        ll miny = c.c.y - c.r, maxy = c.c.y + c.r;
        return miny <= l.p.y and maxy >= l.p.y;
    }
}

void dfs(ll curr){
    if(visited[curr]) return;
    visited[curr] = true;

    if(curr > k+1) possible = false;

    for(auto v : graph[curr]) dfs(v);
}

int main() {
    _; ll n, m; cin >> n >> m >> k;
    vector<circ> circles(k);
    graph.resize(k+4);
    vector<pt> vert = {pt(0,0), pt(0,m), pt(n, m), pt(n,0)};
    vector<line> borda = {line(vert[0], vert[1]), line(vert[1], vert[2]), line(vert[2], vert[3]), line(vert[3], vert[0])};
    forn(i, 0, n){
        cin >> circles[i].c >> circles[i].r;
    }

    forn(i, 0, k){
        forn(j, 0, k){
            if(inter(circles[i], circles[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    forn(i, 0, k){
        forn(j, 0, 4){
            if(inter_line(circles[i], borda[j])){
                graph[i].push_back(k+j);
                graph[k+j].push_back(i);
            }
        }
    }

    visited.assign(k+4, false);
    dfs(k);
    visited.assign(k+4, false);
    dfs(k+1);

    if(possible) cout << "S" << ln;
    if(!possible) cout << "N" << ln;
}