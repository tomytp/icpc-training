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

int main(){
    _;
    ll k; cin >> k;
    v64 stock(k);
    forn(i, 0, k) cin >> stock[i];
    ll n; cin >> n;
    vector<v64> orders(n, v64(k));
    forn(i, 0, n) {
        forn(j, 0, k) {
            cin >> orders[i][j];
        }
    }

    auto valid = [&](ll days) {
        if (days == 0) return true;

        forn(i, 0, stock.size()) {
            ll ing = stock[i];
            forn(j, 0, orders.size()) {
                if (orders[j][i] > INF / days) return false;
                ing -= orders[j][i] * days;
                if (ing < 0) return false;
            }
        }
        return true;
    };

    auto valid2 = [&](ll days) {
        forn(i, 0, stock.size()) {
            forn(j, 0, orders.size()) {
                stock[i] -= orders[j][i] * (days - 1);
            }
        }
        
        forn(i, 0, orders.size()) {
            forn(j, 0, stock.size()) {
                stock[j] -= orders[i][j];
                if (stock[j] < 0) return i + 1;
            }
        }
        return -1ll;
    };


    ll l = 0, r = INF, ans = -1;
    while (l <= r) {
        ll mid = l + (r-l) / 2;
        
        if (valid(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans + 1 << " " << valid2(ans+1) << ln;

    return 0;
}