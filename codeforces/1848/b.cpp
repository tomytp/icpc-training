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

ll val(v64& v, ll n) {
    if (v.size() == 0) return n/2;
    ll mx = INF, mx2 = INF;
    mx = max(n-v.back() - 1, v.front());
    mx2 = min(n-v.back() - 1, v.front());

    forn(i, 0, v.size() - 1) {
        if (v[i+1] - v[i] - 1 > mx2) mx2 = v[i+1] - v[i] - 1;
        if (mx2 > mx) swap(mx, mx2);
    }
    debug(mx);
    debug(mx2);

    return max(mx/2, mx2);
}

void solve() {
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i], v[i]--;
    vector<v64> c(k);
    forn(i, 0, n) {
        c[v[i]].push_back(i);
    }

    ll ans = INF;
    forn(i, 0, k) {
        ans = min(ans, val(c[i], n));
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}