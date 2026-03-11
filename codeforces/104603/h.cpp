#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    ll n2 = n*n;
    vector<p64> coord(n2);
    forn(y, 0, n) {
        forn(x, 0, n) {
            ll p; cin >> p;
            coord[p-1] = {x, y};
        }
    }

    ll ans = 0;
    v64 h(n), v(n);
    for (ll i = n2-1; i >= 0; i--) {
        auto [x, y] = coord[i];
        ll vv = max(h[y] + 1, v[x]);
        ll hh = max(h[y], v[x] + 1);
        v[x] = vv;
        h[y] = hh;
        ans = max(ans, vv);
        ans = max(ans, hh);

    }
    cout << ans << ln;

    return 0;
}