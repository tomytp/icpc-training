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

const ll MOD = 998244353;

inline ll sum(ll a, ll b) { a += b; if (a >= MOD) a -= MOD; return a; }
inline ll sub(ll a, ll b) { a -= b; if (a < 0)  a += MOD; return a; }
inline ll mult(ll a, ll b) { return (a * b) % MOD; }

inline ll pot(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = mult(res, base);
        base = mult(base, base);
        exp >>= 1;
    }
    return res;
}

inline ll inv_mod(ll a) {return pot(a, MOD-2);}


int main(){
    _;
    ll n; cin >> n;
    v64 v(n + 1);
    forn(i, 1, n+1) cin >> v[i];
    v64 dp(n+5, -1);
    v64 prev(100005, -1);
    v64 prevtot(100005, 0);
    dp[0] = 1;
    
    forn(i, 1, n + 1) {
        dp[i] = dp[i-1];
        if (prevtot[v[i]]) {
            dp[i] = sum(dp[i], prevtot[v[i]]);
        }

        prev[v[i]] = i;
        prevtot[v[i]] = sum(prevtot[v[i]], dp[i - 1]);
    }

    cout << dp[n] << ln;
    return 0;
}