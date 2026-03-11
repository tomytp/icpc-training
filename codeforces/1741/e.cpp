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

void solve() {
    ll n; cin >> n;
    v64 v(n+1);
    forn(i, 1, n+1) {
        cin >> v[i];
    }
    vector<bool> dp(n+1);
    dp[0] = true;
    vector<vector<ll>> blocks(n+1);

    forn(i, 1, n+1) {
        ll block = i-(v[i]+1);
        if (block >= 0) {
            blocks[block+1].push_back(v[i]+1);
        }
    }
    forn(i, 1, n+1) {
        if (dp[i-1] == false) continue;
        for (auto b : blocks[i]) {
            debug(i);
            debug(b);
            dp[i+b-1] = true;
        }
        if (i+v[i] <= n) dp[i + v[i]] = true;
    }
    
    cout << ( dp[n] ?"YES" : "NO") << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}