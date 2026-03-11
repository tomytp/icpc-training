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

ll resolve(vector<p64>& vec){
    ll n = sz(vec);
    
    debug(n);
    v64 dp1(n); // sem n-1
    dp1[0] = vec[0].first; 
    dp1[1] = max(vec[0].first + vec[1].second, vec[1].first+vec[0].second);
    
    forn(i,2,n-1){
        dp1[i] = max(dp1[i-1]+vec[i].second, dp1[i-2] + vec[i].first);
    }
    
    if(n == 2) return dp1[n-1];

    v64 dp2(n); // sem 0
    dp2[1] = vec[1].first;
    dp2[2] = max(vec[1].first + vec[2].second, vec[2].first+vec[1].second);
    forn(i,3,n){
        dp2[i] = max(dp2[i-1]+vec[i].second, dp2[i-2] + vec[i].first);
    }

    return max(dp1[n-2], dp2[n-1]);
}

int main(){
    _;
    ll n; cin >> n;
    vector<p64> vec(n);
    forn(i,0,n) cin >> vec[i].first;
    cout << resolve(vec) << ln;;
    return 0;
} 