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

void solve(v64& fib) {
    ll n, m; cin >> n >> m;
    ll l = fib[n];
    ll needed = fib[n] + fib[n - 1];

    string res; res.reserve(m);
    forn(i, 0, m) {
        v64 d(3);
        cin >> d[0] >> d[1] >> d[2];
        sort(d.begin(), d.end());
        if (d[0] >= l && d[2] >= needed) res.push_back('1');
        else res.push_back('0');
    }
    cout << res << ln;
}

int main() {
    _;
    v64 fib(20);
    fib[1] = 1; fib[2] = 2;
    forn(i, 3, 20) fib[i] = fib[i-1] + fib[i-2];
    ll t; cin >> t;
    while (t--) solve(fib);
    return 0;
}