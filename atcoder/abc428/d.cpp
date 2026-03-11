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

ll p10[19];

ll count_squares(ll a, ll b) {
    if (a > b) return 0;
    ll bot = ((ll)(floor(sqrt((long double)b)) + 0.5));
    ll top = ((ll)(floor(sqrt((long double)a)) + 0.5));
    if (top * top < a) ++top;
    if (bot < top) return 0;
    return bot - top + 1;
}

void solve() {
    ll c, d; cin >> c >> d;
    ll ans = 0;

    forn (k, 1, 19) {
        if (p10[k-1] > c + d) break;

        ll lx = 1;
        if (p10[k-1] > c) lx = p10[k-1] - c;

        ll rx = d;
        if (p10[k] - 1 >= c) {
            ll up = (p10[k] - 1) - c;
            if (up < rx) rx = up;
        } else {
            rx = 0;
        }

        if (lx > rx) continue;

        ll lbound = c * p10[k] + (c + lx);
        ll ubound = c * p10[k] + (c + rx);

        ans += count_squares(lbound, ubound);
    }

    cout << ans << ln;
}

int main(){
    _;

    p10[0] = 1;
    forn(i, 1, 19) p10[i] = 10 * p10[i-1];

    ll t; cin >> t;
    while (t--) solve();
    return 0;
}