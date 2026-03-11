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

pair<ll,ll> solve(ll r, v64 &vec){
    ll n = vec.size();

    map<ll,ll> last;
    v64 dp(n,0);
    
    ll max_dp = -1;
    ll max_idx = -1;

    for(ll i = n-1; i >=0; i--){
        dp[i] = 1;

        if(last.find(vec[i]+r) != last.end()) dp[i] += dp[last[vec[i]+r]];
        
        if(dp[i] > max_dp){
            max_dp = dp[i];
            max_idx = i;
        }

        last[vec[i]] = i;  
    }

    return {max_dp, max_idx};
}

int main(){
    _;
    ll n, k; cin >> n >> k;

    v64 vec(n);
    
    forn(i,0, n) cin >> vec[i];

    ll best_pa_size = -1;
    ll best_idx = -1;
    ll r = -1;

    if(n < 2100){
        forn(i,0,n-1){
            auto p = solve(vec[i+1] - vec[i], vec);
            if(best_pa_size < p.first){
                best_pa_size = p.first;
                best_idx = p.second;
                r = vec[i+1] - vec[i];
            }
        }
    } else{
        map<ll,ll> freq;
        forn(i,0,n-1) freq[vec[i+1] - vec[i]]++;

        ll max_f = -INF;
        ll max_diff = 0;

        for(auto p : freq){
            if(p.second > max_f){
                max_f = p.second;
                max_diff = p.first;
            }    
        }

        auto p = solve(max_diff, vec);
        r = max_diff;
        best_pa_size = p.first;
        best_idx = p.second;
    }

    set<ll> remover;

    ll target = vec[best_idx];

    forn(i,0,n){
        if(vec[i] == target){
            target += r;
            continue;
        }
        remover.insert(i);
    }

    if(n - best_pa_size > k){
        cout << -1 << ln;
        return 0;
    }
    
    cout << remover.size() << ln;
    for(ll x : remover){
        cout << x+1 << " ";
    }
    cout << ln;
    return 0;
}