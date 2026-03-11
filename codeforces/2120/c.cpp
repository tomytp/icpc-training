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
    ll n, m; cin >> n >> m;

    ll mn_sum = n;
    ll mx_sum = n * (n + 1) / 2;

    if (m < mn_sum || m > mx_sum) {
        cout << -1 << ln;
        return;
    }

    if (n == 1) {
        cout << 1 << ln;
        return;
    }

    if (m == n) {
        cout << 1 << ln;
        for (ll v = 2; v <= n; ++v)
            cout << 1 << ' ' << v << ln;
        return;
    }

    auto mx = [&](ll r) -> ll {
        return r + (r - 1) * r / 2 + (n - r) * r;
    };
    auto mn = [&](ll r) -> ll {
        return r + n - 1;
    };

    ll lo = 2, hi = n, r = n;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (mn(mid) > m) hi = mid - 1;
        else if (mx(mid) < m) lo = mid + 1;
        else { r = mid; hi = mid - 1; }
    }

    v64 par(n + 1, 0);
    par[1] = r;
    forn(v, 2, n+1) if (v != r) par[v] = 1;

    ll need = m - (r + n - 1);
    ll big_delta = r - 1;

    for (ll v = r + 1; v <= n && need >= big_delta; v++) {
        par[v] = r;
        need -= big_delta;
    }

    for (ll v = r - 1; v >= 2 && need > 0; --v) {
        ll delta = v - 1;
        if (delta <= need) {
            par[v] = r;
            need -= delta;
        }
    }

    cout << r << ln;
    forn(v, 1, n+1) if (par[v]) cout << par[v] << ' ' << v << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}