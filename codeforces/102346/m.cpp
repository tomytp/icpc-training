#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n, c, t; cin >> n >> c >> t;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    function<bool (ll)> valid = [&](ll x) {
        ll curr = 0;
        forn(i, 0, c) {
            ll av = t * x;
            while (curr < n && av >= v[curr]) {
                av -= v[curr];
                curr++;
            }
        }
        return curr == n;
    };

    ll l = 0, r = 10000000000, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (valid(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << ln;

    return 0;
}