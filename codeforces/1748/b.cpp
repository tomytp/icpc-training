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

bool validate(v64& cnt) {
    ll distinct = 0, mx = 0;
    for (auto x : cnt) {
        if (x) distinct++;
        if (x > mx) mx = x;
    }

    return mx <= distinct;
}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll ans = 0;
    ll sz = min(100ll, n);

    for (; sz; sz--) {
        v64 count(10);
        forn(i, 0, sz) {
            count[s[i] - '0']++;
        }
        ans += validate(count);
        forn(i, sz, n) {
            count[s[i] - '0']++;
            count[s[i - sz] - '0']--;
            ans += validate(count);
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