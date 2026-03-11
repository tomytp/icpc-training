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

ll fbet(ll sum, ll k) {
    if (sum == 0) return 1;

    ll l = 1, r = 1000000000000000, ans = 1;
    while (l <= r) {
        ll mid = (l + r)/ 2;

        if (mid * k <= mid + sum) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

void solve() {
    ll k, x, a; cin >> k >> x >> a;
    ll sum = 0;
    forn(i, 0, x+1) {
        ll bet = fbet(sum, k);
        if (a < bet) {
            cout << "NO\n";
            return;
        }
        sum += bet;
        a -= bet;
    }
    cout << "YES\n";
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
