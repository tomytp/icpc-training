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
const ll MOD = 1'000'000'007;

int main(){
    _;
    ll n, h;
    cin >> n >> h;

    v64 fat(n+1);
    fat[0] = 1;
    
    forn(i,1,n+1){
        fat[i] = (fat[i-1]*i)%MOD;
    }

    if(h == 0){
        cout << fat[n] << ln;
        return 0;
    }
    
    v64 k(h);
    v64 dp(h+1);
    v64 acc(h);

    ll tot = 0;
    forn(i,0,h){
        cin >> k[i];
        tot += k[i];
    }

    ll l = n - tot;

    acc[0] = k[0];

    forn(i,1,h){
        acc[i] = k[i] + acc[i-1];
    }

    auto sum = [&](ll left, ll r){
        if(left == 0) return acc[r];
        return acc[r] - acc[left-1];
    };

    dp[0] = fat[l];

    forn(i,1,h+1){
        dp[i] = fat[sum(h-i,h-1)+l];

        forn(j,0,i){
            ll sub = (fat[sum(h-i, h-(j+1))]*dp[j])%MOD;
            dp[i] = (MOD+dp[i]-sub)%MOD;
        }
    }

    cout << dp[h] << ln;
    return 0;
}