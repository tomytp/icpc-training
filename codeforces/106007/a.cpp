#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;
    cout << n << ln;
    forn(i, 1, n) cout << i << " ";

    ll mmc = 1;
    forn(i, 1, n) mmc = lcm(mmc, i);

    cout << mmc << ln;
}

int main() {
    _; ll t; cin >> t;
    while(t--) solve();

    return 0;
}