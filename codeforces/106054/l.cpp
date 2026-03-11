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

int main(){
    _;ll n, g; cin >> n >> g;
    v64 s(n), dp(n), dpant(n, 0), maxdp(n, 0);
    forn(i, 0, n){
        ll a; cin >> a;
        if(i == 0) s[0]= a;
        else s[i] = s[i-1] + a;
    }

    ll sum = 0, k = 1, best = 0;
    while(sum < n){
        forn(i, 0, n-k+1){
            debug(sum);
            if(i < sum) {dp[i] = -INF;}
            else if(i == 0) {dp[i] = -s[0] + g;}
            else {
                debug(i);
                debug(k);
                // ll a = -s[i+k-1];
                // ll b = s[i-1];
                // ll c = maxdp[i-k+1];
                dp[i] = -s[i+k-1] + s[i-1] + maxdp[i-k+1] + g;
            }

            best = max(best, dp[i]);

            if(i == 0) maxdp[i] = dpant[i];
            else maxdp[i] = max(maxdp[i-1], dpant[i]);
        }

        // forn(i, 0, n){
        //     cout << dp[i] << " ";
        // }
        // cout << ln;

        sum += k;
        k++;
        swap(dp, dpant);
    }

    cout << best << ln;

    return 0;
}
 