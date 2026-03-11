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
    string s; cin >> s;
    ll n = 0;
    forn(i, 0, 4) {
        n *= 10;
        n += s[i] - '0';
    }

    ll ans = sqrt(n);
    if (ans * ans == n) {
        cout << 0 << " " << ans << ln;
    } else {
        cout << -1 << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}