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

map<v64, ll> mem;

ll solve(v64 dp, ll ini){
    if(mem.count(dp)) return mem[dp];
    ll sum = 0;
    ll n = sz(dp);
    
    forn(i, 0, n){
        sum += i*dp[i];
    }
    
    sum = sum%5;
    
    ll best = 0;
    forn(i, 0, n){
        if(dp[i] == 0) continue;
        dp[i]--;
        ll curr = solve(dp, ini);
        dp[i]++;
        if(sum - i == ini) curr++;
        best = max(best, curr);
    }
    debugv(dp);
    debug(best);
    return mem[dp] = best;
}

int main() {
    _;
    ll n; cin >> n;
    v64 dp(5, 0);
    forn(i, 0, n){
        ll a; cin >> a;
        dp[a%5]++;
    }

    ll ini = 0;
    forn(i, 0, 5){
        ini += i*dp[i];
    }
    
    ini %= 5;
 
    cout << solve(dp, ini) << ln;

    return 0;
}