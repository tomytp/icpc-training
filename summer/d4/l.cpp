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
ll MAX = 500;

int main(){
    _;
    ll n; cin >> n;

    v64 a(n);
    v64 b(n);

    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];
    
    MAX = min(MAX, n);

    v64 dp(MAX+1, 0);
    dp[0] = a[0]*b[0];
    dp[1] = 0;

    forn(i,1,n){
        
        for (ll t = min(MAX, i); t >= 1; t--) {
            debug(i);
            debug(t);
            dp[t] = max(dp[t-1], dp[t] + a[i] * b[i-t]);
        }

        dp[0] += a[i]*b[i]; 
    }

    ll resp = -INF;
    forn(i,0,MAX+1) resp = max(resp, dp[i]);
    cout << resp << ln;
    return 0;
}