#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
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
const ll A = 10'005;
// const ll A = 200;

int main() {
    _;
    ll n; cin >> n;
    ll totb = 0;
    v64 a(n);
    v64 b(n);

    forn(i,0,n) {
        cin >> a[i] >> b[i];
        totb += b[i];
    }

    v64 dp(n*A+1, -1);
    dp[0] = 0;

    forn(i,0,n){
        for(ll j = n*A-a[i]; j --> 0;){
            if(dp[j] == -1) continue;
            dp[j+a[i]] = max(dp[j+a[i]], dp[j]+b[i]);
        }
    }
    debugv(dp);
    
    trace(
        forn(i,1,n*A+1){
            if(dp[i] == -1) continue;
            cout << i << " " << dp[i] << ln;
        }
    );
    ll best = totb;

    forn(i,1,n*A+1){
        if(dp[i] == -1) continue;
        ll t =  max(i, totb - dp[i]);
        debug(t);
        best = min(best, t);
    }
    cout << best << ln;
    return 0;
} 