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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll count_zero(ll b, ll n){
    ll ans = 0;
    while (n>=1)
    {
        if(n%b == 0)ans++;
        n /= b;
    }
    return ans;
}
int main() {
    _;
    
    ll n = 95;
    forn(i,2,96){
        cout << i << " " << count_zero(i,n) << ln;
    }
    
    return 0;
}