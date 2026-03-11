#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    v64 dp(5);
    
    forn(i,0,n){
        ll x; cin >> x;
        dp[x%5]++;
    }

    ll resp = dp[0];
    dp[0] = 0;

    debugv(dp);
    debug(resp);

    forn(i,1,5){
        ll aux = min(dp[i], dp[5-i]);
        resp += aux;
        dp[i] -= aux;
        dp[5-i] -= aux;
    }

    debugv(dp);
    debug(resp);
        
    if(dp[4] > 0){
        v64 temp = dp;

        forn(i,1,5) dp[i] = temp[5-i];
    }
    if(dp[3] > 0){
        v64 temp = dp;
        dp[1] = temp[3];
        dp[2] = temp[1];
        dp[3] = 0;
        dp[4] = 0;
    }

    debugv(dp);
    debug(resp); 
    
    ll x1 = dp[1];
    ll x2 = dp[2];

    ll best = 0;

    forn(i,0,4){
        ll curr = i;
        ll y1 = x1 - 3*i;
        ll y2 = x2 - i;
        if(y1 < 0 || y2 < 0) continue;
        ll aux = min(y1, y2/2);
        y1 -= aux;
        y2 -= 2*aux;
        curr += aux;
        curr += y1/5 + y2/5; 
        best = max(best, curr);
    }

    cout << resp + best << ln;
    return 0;
}