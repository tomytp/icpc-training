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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    map<ll, ll> mp;
    forn(i,0 , n) mp[v[i]]++;
    v64 cnts; cnts.reserve(n);
    for (auto x : mp) cnts.push_back(x.second);
    sort(cnts.begin(), cnts.end());
    
    auto test = [&](ll x) {
        if (x > cnts.back()) return false;
        ll to_use = sz(cnts) - 1;
        if (x < cnts.back()) to_use++;
        if(x > to_use) return false;
        return true;
    };

    ll l = 0, r = INF, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        debugv(cnts);
        debug(mid);
        debug(test(mid));
        if (test(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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