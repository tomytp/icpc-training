#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;


void solve() {
    ll n, k; cin >> n >> k;
    v64 a(n);

    ll car_count = 0;
    
    forn(i, 0, n) {
        cin >> a[i];
        car_count += a[i];
    }

    auto count_sum = [&](ll x) -> p64 {
        ll cnt = 0, sum = 0;
        for (ll ai : a) {
            ll c1 = min(ai, x);
            cnt += c1;
            
            sum += c1 * (c1 + 1) / 2;
            
            if (x > ai + k) {
                ll c2 = x - ai - k;
            
                cnt += c2;
            
                ll start = ai + k + 1;
                ll endv  = x;
                sum += c2 * (start + endv) / 2;
            }
        }

        return {cnt, sum};
    };

    ll l = 1, r = 1, ans = -1;
    while (count_sum(r).first < car_count) r <<= 1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (count_sum(mid).first >= car_count) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    auto p = count_sum(ans);
    cout << p.second - ((p.first - car_count) * ans) << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}