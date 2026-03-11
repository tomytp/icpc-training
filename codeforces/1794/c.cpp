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

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    reverse(v.begin(), v.end());
    
    ll len = 0;
    ll i = 0;
    v64 ans;
    
    forn(j, 0, n) {
        i = max(i, j);
       
        while (i < n) {
            if (v[i] < len + 1) break;
            len++;
            i++;
        }

        ans.push_back(max(1ll, len));
        
        if (len > 0) len--;
    }

    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
    cout << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}