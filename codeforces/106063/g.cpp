#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void) 0
    #define debug(x) cout << __LINE__  << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll s, t , b; cin >> s >> t >> b;
    ld h1 = (ld)s, h2 = (ld)t, bd = (ld)b;
    ld aux = log(h2/h1);
    aux = aux/log((bd-1)/bd);
    cout << (ll)(ceil((aux))+0.5)<< ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}