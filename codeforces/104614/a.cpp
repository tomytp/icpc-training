#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll delta;
vector<vector<vector<bool>>> maze;

ll calc_delta(char d1, char d2){
    map<char, ll> mp = {{'N',0 }, {'E',1 }, {'S',2 }, {'W',3}};
    ll idx1 = mp[d1];
    ll idx2 = mp[d2];

    return (idx2 - idx1+4)%4;
}

struct pos{
    ll x1, x2, y1, y2;
    pos(ll x1_, ll x2_, ll y1_, ll y2_) : x1(x1_), x2(x2_), y1(y1_), y2(y2_) {};
};

pair<pos, ll> walk_pos(pos curr, ll dir){
    pos resp = curr;
    ll bump = 0;

    if(maze[resp.x1][resp.y1][dir] == true) {
        resp.x1 += rot(dir).first;
        resp.y1 += rot(dir).second;
    }
    else bump++;

    if(maze[resp.x2][resp.y2][dir] == true) {
        resp.x2 += rot(dir+delta).first;
        resp.y2 += rot(dir+delta).second;
    }
    else bump++;

    return {resp, bump};
}

pair<ll, ll> rot(ll dir){
    dir = (dir+4)%4;
    if(dir == 0) return {1,0};
    if(dir == 1) return {0,1};
    if(dir == 2) return {-1,0};
    if(dir == 3) return {0,-1};    
    assert(false);
}

int main(){
    _; ll r, c, e; cin >> r >> c >> e;
    ll c1, r1, c2, r2;
    char d1, d2;
    cin >> c1 >> r1 >> d1 >> c2 >> r2 >> d2;

    maze(r, vector<vector<bool>>(c , vector<bool>(4, true)));

    forn(i, 0, r){
        maze[i][0][3] = false;
        maze[i][c-1][1] = false;
    }

    forn(i, 0, c){
        maze[0][i][2] = false;
        maze[r-1][i][0] = false;
    }

    maze[0][e-1][2] = true;

    delta = calc_delta(d1, d2);

    ll n; cin >> n;
    forn(kjhyu, 0, n){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        maze[x][y][0] = false;
        maze[x+1][y][2] = false;
    }

    cin >> n;
    forn(kjhyu, 0, n){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        maze[x][y][1] = false;
        maze[x][y+1][3] = false;
    }

    map<pos, vector<pair<pos, ll>>> grafo;

    forn(x1, 0, r)
    forn(x2, 0, r)
    forn(y1, 0, c)
    forn(y2, 0, c){
        pos curr_pos = pos(x1,x2,y1,y2);
        auto walk = walk_pos()
    }
    


    return 0;
}