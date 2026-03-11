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



void solve() {
    ll n; cin >> n;
    v64 pow = {1, 10, 100, 1000, 10000, 100000};
    v64 ans;
    ll curr = 0;
    while(n) {
        if (n%10) ans.push_back(n%10 * pow[curr]);
        n/=10;
        curr++;
    }

    cout << ans.size() << ln;
    forn(i, 0, ans.size()) {
        cout << ans [i] << " \n"[i==ans.size() -1 ];
    }

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();

    return 0;
}