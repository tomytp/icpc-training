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
    vector<p64> v(n);
    forn(i, 0, n) cin >> v[i].first >> v[i].second;

    auto possible = [&](ll mid) {
        ll lb = 0, rb = 0;
        forn(i, 0, n) {
            lb -= mid;
            rb += mid;

            if (lb < v[i].first) lb = v[i].first;
            if (rb > v[i].second) rb = v[i].second;

            if (lb > rb || lb > v[i].second || rb < v[i].first) return false;
        }
        return true;
    };

    ll l = 0, r = 10000000000, ans = -1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if (possible(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}