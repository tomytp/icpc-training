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
const ll MOD = 998244353;
const ll MAXN = 100010;

ll p2[MAXN];

void solve() {
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    v64 reva(n), revb(n);
    forn(i, 0, n) {
        reva[a[i]] = i;
        revb[b[i]] = i;
    }
}

int main(){
    _;
    p2[0] = 1;
    forn(i, 1, MAXN) p2[i] = (p2[i-1] << 1) % MOD;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}