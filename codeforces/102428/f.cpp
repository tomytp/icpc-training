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
const ll mod = 1'000'000'007;

int main(){
    _;
    ll a, b; cin >> a >> b;
        
    vector<v64> dp(a+5, v64(b+5, -1));
    b -= a;

    function<ll (ll, ll)> f = [&](ll n, ll k) {
        if (n < 0 || k < 0) return 0ll;
        if (n == 1) return 1ll;
        if (k == 1) return n;
        if (k == 0) return 1ll;
        if (n == 0) return 0ll;
        auto p = dp[n][k];
        if (p != -1) return p;
        dp[n][k]  = (2 * f(n-1, k)) % mod;
        dp[n][k]  = (dp[n][k] - f(n-2, k) + mod) % mod;   // garante positivo
        dp[n][k]  = (dp[n][k] + f(n, k - n)) % mod;

        return dp[n][k];
    };

    cout << (f(a, b) % mod + mod) % mod << ln;    
    return 0;
}