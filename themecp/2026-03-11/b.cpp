#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n, x; cin >> n >> x;
    if (x == 0 && n == 1) {
        cout << -1 << ln;
        return;
    }

    if (x == 0 && n % 2 == 0) {
        cout << n << ln;
        return;
    }

    if (x == 0 && n%2 == 1) {
        cout << 5 + n-2 << ln;
        return;
    }

    if (n <= __builtin_popcountll(x)) {
        cout << x << ln;
        return;
    }

    if (n == 2) {
        cout << x + 2 * (1ll << (__builtin_ctzll(~x))) << ln;
        return;
    }

    if (x == 1) {
        if (n % 2 == 1) {
            cout << n << ln;
            return;
        } else {
            cout << 5 + n - 2 << ln;
            return;
        }
    }

    if (n % 2 == __builtin_popcountll(x) % 2) {
        cout << x + n-__builtin_popcountll(x) << ln;
        return;
    } else {
        cout << x + n - __builtin_popcountll(x) + 1 << ln;
        return;
    }
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
