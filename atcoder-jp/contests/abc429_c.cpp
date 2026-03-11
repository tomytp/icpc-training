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

int main(){
    _;
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    map<ll, ll> cnt;
    forn(i, 0, n) cnt[v[i]]++;
    ll ans = 0;
    for (auto [k, val] : cnt) {
        if (val < 2) continue;
        ll ways = (val * (val-1)) / 2;
        ways *= n - val;
        ans += ways;
    }

    cout << ans << ln;
    return 0;
}