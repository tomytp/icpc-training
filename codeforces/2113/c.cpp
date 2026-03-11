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


void build_prefix(vector<string>& g, vector<v64>& p) {
    ll n = g.size(), m = g[0].size();
    p.assign(n + 1, std::vector<ll>(m + 1, 0));
    for (ll i = 0; i < n; ++i)
    for (ll j = 0; j < m; ++j)
        p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + (g[i][j] == 'g');
}

inline ll rect_sum(ll x1, ll y1, ll x2, ll y2, vector<v64>& p) {
    if (x1 > x2 || y1 > y2) return 0;
    ++x2; ++y2;
    return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
}

inline ll gold_destroyed(ll x, ll y, ll k, vector<v64>& p, ll n, ll m) {
    ll xi1 = max(0LL, x-k+1);
    ll yi1 = max(0LL, y-k+1);
    ll xi2 = min(n-1, x+k-1);
    ll yi2 = min(m-1, y+k-1);
    return rect_sum(xi1, yi1, xi2, yi2, p);
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];
    vector<v64> p;
    build_prefix(v, p);

    ll mn = INF;
    ll counter = 0;
    forn(i, 0, n) {
        forn(j, 0, m) {
            if (v[i][j] == 'g') counter++;
            if (v[i][j] == '.') mn = min(mn, gold_destroyed(i, j, k, p, n, m));
        }
    }

    cout << counter - mn << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
}
