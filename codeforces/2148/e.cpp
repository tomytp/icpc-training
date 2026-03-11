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
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    if (n%k != 0) {
        cout << 0 << ln;
        return;
    }
    map<ll,ll> mp;
    forn(i,0, n) {
        mp[v[i]]++;
    }
    for (auto& [key, val] : mp) {
        if (val % k != 0) {
            cout << 0 << ln;
            return;
        }
        val /= k;
    }

    map<ll,ll> curr;
    ll i = 0, j = 0;
    ll ans = 0;
    while (i < n && j <= n) {
        while (j < n) {
            if (curr[v[j]] < mp[v[j]]) {
                curr[v[j]]++;
                j++;
            } else {
                break;
            }
        }
        ans += j - i;
        curr[v[i]]--;
        i++;
    }   
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}