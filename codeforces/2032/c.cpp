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
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    ll bs = 2;
    ll a = 0, b = 2;
    while (a < (n-1) && b < n) {
        if (v[a] + v[a+1] > v[b]) {
            bs = max(bs, b-a+1);
            b++;
        } else {
            a++;
            if (a > (b-1)) b++;
        }
    }
    cout << n-bs << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
