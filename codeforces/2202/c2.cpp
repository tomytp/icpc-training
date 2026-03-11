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

    ll ans = n * (n + 1) * (n + 2) / 6;
    stack<p64> st;
    ll tot = 1;
    st.push({v[0], 1});
    
    forn(j, 1, n) {
        ll prev_hi = v[j - 1];
        if (v[j] > prev_hi + 1) {
            while (st.size()) st.pop();
            tot++;
            st.push({v[j], tot});
        } else {
            ll thresh = v[j] - 1;
            ll merged = 0;
            while (st.size() && st.top().first > thresh) {
                merged += st.top().second;
                st.pop();
            }
            ans -= (tot - merged) * (n - j);
            tot++;
            st.push({v[j], merged + 1});
        }
    }
    
    cout << ans << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
