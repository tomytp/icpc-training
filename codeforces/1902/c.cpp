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

void solve() {
    ll n; cin >> n;
    debug(n);
    v64 v(n);
    ll mx = -INF;
    forn(i, 0, n) cin >> v[i], mx = max(mx, v[i]);
    if (n == 1) {
        cout << 1 << ln;
        return;
    }
    ll g = max(mx - v[0], mx - v[1]);
    forn(i, 0, n) g = gcd(g, mx - v[i]);
    set<ll> st;
    forn(i, 0, n) st.insert(v[i]);
    debug(g);
    ll cand = mx;
    ll ans = 0;
    while (st.count(cand)) cand -= g, ans++;
    forn(i, 0, n) {
        ans += (mx - v[i]) / g;
    }
    cout << ans << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
