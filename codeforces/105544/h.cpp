#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll c; cin >> c;
    v64 v;
    ll aux;
    while (cin >> aux) v.push_back(aux);   
    
    ll n = v.size() / 2;
    v64 rev(n), cost(n);
    forn(i, 0, n) {
        rev[i] = v[i];
        cost[i] = v[n+i];
    }

    v64 dp(c+1);
    forn(i,0,n) {
        for (ll j = c; j >= 0; j--) {
            if (j + cost[i] > c) continue;
            dp[j+cost[i]] = max(dp[j+cost[i]], dp[j] + rev[i]);
        }
    }


    cout << *max_element(dp.begin(), dp.end()) << ln;     
    return 0;
}