#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll as = 0, bs = 0;
    forn(i, 0, n) {
        if (s[i] == 'a') as++;
        else bs++;
    }

    ll diff = as - bs;

    if (diff == 0) {
        cout << 0 << ln;
        return;
    }

    debug(diff);
    map<ll, ll> tst;
    tst[0] = -1;
    ll pref = 0;
    ll ans = INF;
    forn(i, 0, n) {
        if (s[i] == 'a') pref++;
        else pref--;

        ll want = pref - diff;
        if (tst.count(want)) {
            ans = min(ans, i - tst[want]);
        }
        tst[pref] = i;
    }
    if (ans < n) {
        cout << ans << ln;
        return;
    }
    cout << -1 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}