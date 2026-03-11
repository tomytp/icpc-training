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
    v64 v0(n);
    forn(i, 0, n) cin >> v0[i];

    v64 v;
    v.push_back(v0[0]);
    forn(i, 1, n) if (v0[i] != v0[i-1]) v.push_back(v0[i]);
    n = sz(v);
    v64 v2;
    v2.push_back(v[0]);
    forn(i, 1, n-1) {
        ll aux = 0;
        if (v[i] > v[i-1]) aux++;
        if (v[i] > v[i+1]) aux++;
        if (aux != 1) v2.push_back(v[i]);
    }
    v2.push_back(v[n-1]);
    n = sz(v2);
    ll ans = 0;
    forn(i, 1, n-1) {
        ans = max(ans, v2[i] - max(v2[i-1], v2[i+1]));
    }
    cout << ans << ln;
    return 0;
}
