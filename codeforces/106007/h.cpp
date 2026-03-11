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

void solve() {
    ll n; cin >> n;
    v64 a(n), b;
    forn(i, 0, n) cin >> a[i];
    b.push_back(a[0]);
    while(b.size() < n) {
        ll i = b.size();
        if (i == n-1) {
            b.push_back(a[n-1]);
            break;
        }
        if (a[i] <= a[i + 1]) {
            b.push_back(a[i]);
            continue;
        }
        if (i + 2 < n) {
            b.push_back(a[i + 1]);
            b.push_back(a[i]);
            b.push_back(a[i+2]);
        } else {
            b.push_back(a[i]);
            b.push_back(a[i + 1]);
        }
    }

    forn(i, 0, n) cout << b[i] << " \n"[i==n-1];
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}