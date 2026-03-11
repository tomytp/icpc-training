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
    ll n, q; cin >> n >> q;
    v64 b(n); 
    forn(i,0,n) cin >> b[i];

    v64 qx(q), qy(q), qz(q);
    forn(i,0,q) {
        cin >> qx[i] >> qy[i] >> qz[i]; 
        qx[i]--; qy[i]--; qz[i]--; 
    }
    v64 is_safe(n, false);
    v64 lb(n);

    for (ll i = q-1; i >= 0; i--) {
        ll x = qx[i], y = qy[i], z = qz[i];
        if (is_safe[z]) continue;

        lb[x] = max(lb[x], b[z]);
        lb[y] = max(lb[y], b[z]);
        is_safe[z] = true;
    }

    v64 a(n);
    forn(i, 0, n) {
        a[i] = max(lb[i], b[i]);
    }

    v64 a2 = a;

    forn(i, 0, q) {
        ll x = qx[i], y = qy[i], z = qz[i];
        a[z] = min(a[x], a[y]);
    }

    if (a != b) {
        cout << -1 << ln;
        return;
    }    


    forn(i, 0, n) cout << a2[i] << " \n"[i==n-1];
}


int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}