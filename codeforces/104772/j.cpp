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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    ll upper = 0, curr_min = 0;
    forn(i, 0, n) {
        if (a[i] > b[curr_min]){
            upper++;
            curr_min++;
        }
    }

    function<bool (ll)> test = [&](ll k) {
        forn(i, 0, k) {
            if (b[i] > a[n-k+i]) {
                return false;
            }
        }
        forn(i, k, n) {
            if (b[i] < a[i-k]) {
                return false;
            }
        }
        return true;
    };

    ll l = 0, r = upper;
    ll ans = r;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (test(mid)) {
            r = mid - 1;
            ans = mid; 
        } else {
            l = mid + 1;
        }
    }

    cout << upper - ans + 1 << ln;
    forn(i, ans, upper+1) {
        cout << i << " ";
    }
    cout << ln;
    return 0;
}