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

int main() {
    _;
    ll n; cin >> n;
    v64 suf(n-1);
    forn(i, 0, n-1) cin >> suf[i];
    v64 dive(n);
    forn(i, 0, n) cin >> dive[i];
    v64 fix(n+1);
    forn(i, 0, n+1) cin >> fix[i];

    ll mn = INF;
    suf.push_back(0);
    for (ll i = n-2; i >= 0; i--) {
        suf[i] += suf[i+1];
    }

    forn(i, 0, n) {
        ll var = max(var, fix[i+1]);

        var += suf[i];
        mn = min(mn, var);
    }

    ll ans = accumulate(dive.begin(), dive.end(), 0ll);// all dives
    ans += mn; // best fix + dist
    ans += suf[0]; // all dist
    cout << ans << ln;




    return 0;
}