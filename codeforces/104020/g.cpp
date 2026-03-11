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

map<v64, ll> mp;

ll func(v64 dp, ll k){
    if(mp.count(dp)) return mp[dp];
    
    ll sum = 0;
    forn(i,0,k) sum += dp[i]*i;
    sum %= k;

    ll best = 0;
    forn(i,0,k){
        if(dp[i] == 0) continue;
        dp[i]--;
        ll curr = func(dp, k);
        if(i == sum) curr++;
        dp[i]++;

        best = max(best, curr);
    }

    return mp[dp] = best;
}

int main() {
    _;
    ll n, k; cin >> n >> k;
    v64 v(n);
    ll tot = 0;
    forn(i, 0, n) cin >> v[i], tot += v[i];
    tot /= k;

    v64 dp(k);
    forn(i, 0, n) dp[v[i] % k]++;
   
    ll grupos = dp[0];
   
    dp[0] = 0;
    forn(i,1,k){
        if(2*i == k){
            ll temp = dp[i]/2;
            grupos += temp;
            dp[i] -= 2*temp;
            continue;
        }
        ll temp = min(dp[i], dp[k-i]);
        dp[i] -= temp;
        dp[k-i] -= temp;
        grupos += temp;
    }


    grupos += func(dp, k);

    tot -= grupos;

    cout << tot << ln;

    return 0;
}