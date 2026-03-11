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

bool valid(ll a, ll b, ll x1, ll y1, ll x2, ll y2) {
    ll dx = abs(x1 - x2);
    ll dy = abs(y1 - y2);

    if (dx % a && dy % b) return false;
    if (!dx && dy % b) return false;
    if (!dy && dx % a) return false;
    return true;
}

void solve() {
    ll w, h, a, b; cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (valid(a, b, x1, y1, x2, y2)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    _;
    ll t;  cin >> t;
    while (t--) solve();
    return 0;
}