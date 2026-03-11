#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

const ll INF = 1'000'000;

int main() {
    _;
    ll xs, ys; cin >> xs >> ys;
    ll xr, yr; cin >> xr >> yr;
    ll xp, yp; cin >> xp >> yp;

    vector<p64> patha, pathb;

    if (ys <= yp) {
        patha.emplace_back(xs, -INF);
        patha.emplace_back(INF, -INF);
        patha.emplace_back(INF, INF);      
    } else {
        patha.emplace_back(xs, INF);
        patha.emplace_back(INF, INF);
    }

    if (yr <= yp) {
        pathb.emplace_back(INF, -INF);
        pathb.emplace_back(xr, -INF);
    } else {
        pathb.emplace_back(xr, INF);
    }
    cout << sz(patha) + sz(pathb) << ln;
    forn(i, 0, size(patha)) {
        cout << patha[i].first << " " << patha[i].second << ln;
    }
    forn(i, 0, size(pathb)) {
        cout << pathb[i].first << " " << pathb[i].second << ln;
    }
    return 0;
}