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
    ll n, m, k; cin >> n >> m >> k;
    v64 a(n), b(m);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, m) cin >> b[i];
    string s; cin >> s;
    v64 pref(k), low(k), high(k);
    pref[0] = (s[0] == 'L') ? -1 : 1;
    low[0] = max(0ll, -pref[0]);
    high[0] = max(0ll, pref[0]);

    forn(i, 1, k) {
        pref[i] = pref[i-1] + ((s[i] == 'L')? -1 : 1);
        low[i] = -min(-low[i-1], pref[i]);
        high[i] = max(high[i-1], pref[i]);
    }
    v64 deaths(k);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    forn(rob, 0, n) {
        ll lspike = -1 + (ll)(lower_bound(b.begin(), b.end(), a[rob]) - b.begin());
        ll rspike = lspike + 1;


        // a[rob] - low[i] <= b[lspike]
        // low[i] <= a[rob] - b[lspike]
        debug(rob);
        ll i = INF;
        if (lspike != -1) {
            debug(b[lspike]);
            i = (ll)(lower_bound(low.begin(), low.end(), a[rob] - b[lspike]) - low.begin());
        }
        
        // a[rob] + high[i] >= b[rspike]
        // high[i] >= 
        ll i2 = INF;
        if (rspike < m) {
            debug(b[rspike]);
            debug(a[rob]);
            i2 = (ll)(lower_bound(high.begin(), high.end(), b[rspike] - a[rob]) - high.begin());
        }
        debug(i);
        debug(i2);
        if (min(i, i2) < k && min(i, i2) >= 0) deaths[min(i, i2)]++;
    }

    ll sum = 0;
    forn(i, 0, k) {
        sum += deaths[i];
        cout << n-sum << " \n"[i==k-1];
    }
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
 