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
    map<ll, ll> mp;
    forn(i, 0, n) cin >> v[i], mp[v[i]]++;
    
    ll tot = 0;
    ll ans = 0;
    for (auto [k, cnt] : mp) {
        if (cnt >= 3) ans += (cnt*(cnt-1)*(cnt-2)) / 6;
        if (cnt >= 2) ans += ((cnt*(cnt-1))/2) * tot;
        tot += cnt;
    }
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}