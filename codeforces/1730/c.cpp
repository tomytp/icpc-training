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
    string s; cin >> s;
    ll n = s.size();
    string s2 = s;
    char sofar = s.back();
    for (ll i = n-1; i >= 0; i--) {
        sofar = min(sofar, s[i]);
        s2[i] = sofar;
    }
    map<ll, ll> cnt;
    forn(i, 0, n) {
        if (s[i] == s2[i]) cnt[s[i] - '0']++;
        else cnt[min((s[i] - '0' + 1), 9)]++;
    }
    for ( auto [c, k] : cnt) {
        forn(i, 0, k) cout << c;
    }
    cout << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}