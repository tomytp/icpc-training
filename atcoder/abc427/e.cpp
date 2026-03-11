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
struct State { ll lx, rx, ly, ry, x, y; };
ll dist[13][13][13][13][25][25];

bool inb(ll x, ll l, ll r) { 
    return l <= x && x < r; 
}

int main(){
    _;
    ll h, w; cin >> h >> w;
    vector<string> m(h);
    forn(i, 0, h) cin >> m[i];
    
    memset(dist, 0x3f, sizeof(dist));

    vector<v64> cnt(h, v64(w));
    forn(i, 0, h) {
        forn(j, 0, w) {
            if (i > 0) cnt[i][j] += cnt[i-1][j];
            if (j > 0) cnt[i][j] += cnt[i][j-1];
            if (i && j) cnt[i][j] -= cnt[i-1][j-1];
            cnt[i][j] += (m[i][j] == '#');
        }
    }


    auto clear = [&](ll lx, ll rx, ll ly, ll ry) -> ll {
        if (lx >= rx || ly >= ry) return true;
        ll r = rx - 1, c = ry - 1;
        ll ans = cnt[r][c];
        if (lx > 0) ans -= cnt[lx-1][c];
        if (ly > 0) ans -= cnt[r][ly-1];
        if (lx > 0 && ly > 0) ans += cnt[lx-1][ly-1];
        return ans == 0;
    };


    ll px, py;
    forn(i, 0, h) forn(j, 0, w) if (m[i][j] == 'T') px = i, py = j;

    queue<State> q;
    dist[0][h][0][w][h][w] = 0;
    q.push({0, h, 0, w, h, w});

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        ll dcur = dist[cur.lx][cur.rx][cur.ly][cur.ry][cur.x][cur.y];

        if (clear(cur.lx, cur.rx, cur.ly, cur.ry)) {
            cout << dcur << ln;
            return 0;
        }

        const ll dx[4] = {+1, -1, 0, 0};
        const ll dy[4] = {0, 0, +1, -1};

        forn(k, 0, 4) {
            ll nx = cur.x + dx[k];
            ll ny = cur.y + dy[k];
            if (nx < 0 || nx > 2*h || ny < 0 || ny > 2*w) continue;

            ll nlx = max(cur.lx, nx - h);
            ll nrx = min(cur.rx, nx);
            ll nly = max(cur.ly, ny - w);
            ll nry = min(cur.ry, ny);

            if (nlx < 0 || nlx > h || nrx < 0 || nrx > h || nly < 0 || nly > w || nry < 0 || nry > w) continue;
            if (nlx > nrx || nly > nry) continue;

            ll x = px + (nx - h);
            ll y = py + (ny - w);
            if (inb(x, nlx, nrx) && inb(y, nly, nry) && m[x][y] == '#') continue;

            ll &cell = dist[nlx][nrx][nly][nry][nx][ny];
            if (cell != INF) continue;
            cell = dcur + 1;
            q.push({nlx, nrx, nly, nry, nx, ny});
        }
    }

    cout << -1 << ln;
    

    return 0;
}