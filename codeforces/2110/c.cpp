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

void solve() {
    ll n; cin >> n;
    v64 d(n+1);
    forn(i, 1, n + 1) cin >> d[i];
    v64 l(n+1), r(n+1);
    forn(i, 1, n + 1) cin >> l[i] >> r[i];

    v64 lo(n+1), hi(n+1);
    bool deu_bom = true;

    forn(i, 1, n + 1) {
        ll nl = INF, nh = -INF;
        bool f0 = false, f1 = false;

        if (d[i] != 1) {
            ll a = max(lo[i-1], l[i]);
            ll b = min(hi[i-1], r[i]);
            if (a <= b) {
                f0 = true;
                nl = min(nl, a);
                nh = max(nh, b);
            }
        }

        if (d[i] != 0) {
            ll a = max(lo[i-1] + 1, l[i]);
            ll b = min(hi[i-1] + 1, r[i]);
            if (a <= b) {
                f1 = true;
                nl = min(nl, a);
                nh = max(nh, b);
            }
        }

        if ((!f0 && !f1) || (d[i] == 0 && !f0) || (d[i] == 1 && !f1)) {
            deu_bom = false;
            break;
        }

        lo[i] = nl;
        hi[i] = nh;
    }

    if (!deu_bom) {
        cout << -1 << ln;
        return;
    }

    v64 h(n + 1);
    h[n] = lo[n];

    for (ll i = n; i >= 1; i--) {
        if (d[i] == 0) {
            h[i-1] = h[i];
        } else if (d[i] == 1) {
            h[i-1] = h[i] - 1;
        } else {
            if (h[i] >= l[i] && h[i] <= r[i] && h[i] >= lo[i-1] && h[i] <= hi[i-1]) {
                d[i] = 0;
                h[i-1] = h[i];
            } else {
                d[i] = 1;
                h[i-1] = h[i] - 1;
            }
        }
    }
    forn(i, 1, n+1) cout << d[i] << " \n"[i==n];
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();

    return 0;
}