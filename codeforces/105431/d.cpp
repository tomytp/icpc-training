#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops,inline")
using namespace std;

typedef int ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sz(x) ((ll) x.size())

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

vector<v64> dp;
v64 a, b;

ll rec(ll i, ll j){
    if(i == -1 || j == -1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]){

        return dp[i][j] = rec(i-1,j-1) + 1;
    }

    return dp[i][j] = max(rec(i-1, j), rec(i,j-1));
}

int main() {
    _;
    ll n, k;
    cin >> n >> k;
    a.resize(n*k), b.resize(n*k);

    forn(i,0,n*k) cin >> a[i];
    forn(i,0,n*k) cin >> b[i];

    dp.resize(n*k, v64(n*k, -1));
    
    cout << rec(n*k-1, n*k-1) << ln;
    return 0;
}