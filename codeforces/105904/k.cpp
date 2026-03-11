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

inline ll sum(ll a, ll b){
    ll s = a+b;
    return (s < MOD ? s : s - MOD);
}

int main(){
    _;
    ll n, k; cin >> n >> k;

    v64 dp(n+1);
    dp[0] = 1;
    forn(i, 1, n+1) {
        if (i == k) continue;
        forn(j, i, n + 1) {
            dp[j] = sum(dp[j], dp[j-i]);
        }
    } 

    cout << dp[n] << ln;
    return 0;
}