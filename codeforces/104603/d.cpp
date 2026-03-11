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
    ll k; cin >> k;
    v64 c(k), p(k);
    forn(i, 0, k) cin >> c[i];
    forn(i, 0, k) cin >> p[i];

    function<bool (ll x)> can = [&](ll x) {
        ll nxt = p[0];
        forn(i, 0, k) {
            if (c[i] * x > nxt) return false;
            nxt -= c[i] * x;
            if (i+1 < k) nxt += p[i+1];
        }
        return true;
    };

    ll l = 0, r = 1000000000;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (can(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << ans << ln;


    return 0;
}