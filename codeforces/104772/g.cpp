#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline")

#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

// const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 503;
ll MOD = -1;

ll dp[MAXN][MAXN][MAXN];

int main() {
    _;
    ll n, p_;
    cin >> n >> p_ >> MOD;
    

    forn(k,0,n+1){
        forn(p,0,n+1){
            ll ans = -1;
            if(p > 1) ans = 0;
            if(p == 1) ans = (k%2);
            if(p == 0) ans = 1 - (k%2);
            dp[1][k][p] = ans;
        }
    }    

    forn(b,2,n+2-p_)
    forn(k,0,n+2-p_)
    forn(p,0,min(2*k+1,n+2-p_)){
        ll aux = (dp[b-1][k][p]+ (b > k ? 0 :dp[b][k-b][p^b]));
        if(aux >= MOD) aux -= MOD;
        dp[b][k][p] = aux;
    }

    // forn(i,0,n){
    //     forn(j,0,n)
    //         cout << dp[i][j][n] << " ";
    //     cout << ln;
    // }
    cout << dp[n-p_][n-p_][p_] << ln;
    return 0;
}