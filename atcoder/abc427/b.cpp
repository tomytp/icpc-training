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

ll f(ll x) {
    ll ans = 0;
    while(x) {
        ans += x%10;
        x/=10;
    }
    return ans;
}

int main(){
    _;
    ll n; cin >> n;
    v64 v(n+1);
    v[0] = 1;
    v[1] = 1;
    forn(i, 2, n+1) {
        v[i] = v[i-1] + f(v[i-1]);
    }
    cout << v[n] << ln;
    return 0;
}