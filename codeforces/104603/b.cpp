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

int main() {
    _;
    ll n; cin >> n;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];
    ll ans = 0;
    forn(i, 0, n) {
        ll j = 1;
        while (j < n) {
            if (v[i][j] == 'N' && v[i][j-1] == 'N') {
                ans++;
                j++;
            }
            j++;
        }
    }
    cout << ans << ln;
    return 0;
}