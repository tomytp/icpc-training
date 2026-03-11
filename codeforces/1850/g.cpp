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

void solve() {
    ll n; cin >> n;
    map<ll, ll> a, b, c, d;
    forn(i, 0, n) {
        ll x, y; cin >> x >> y;
        a[x]++;
        b[y]++;
        c[x+y]++;
        d[x-y]++;
    }

    ll ans = 0;
    for (auto [k, v] : a) {
        if (v > 1) ans += v * (v-1);
    }
    for (auto [k, v] : b) {
        if (v > 1) ans += v * (v-1);
    }
    for (auto [k, v] : c) {
        if (v > 1) ans += v * (v-1);
    }
    for (auto [k, v] : d) {
        if (v > 1) ans += v * (v-1);
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}