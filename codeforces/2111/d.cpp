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
    ll n, m; cin >> n >> m;
    vector<p64> v(m);
    forn(i, 0, m) {
        cin >> v[i].second;
        v[i].first = v[i].second / 100;
    }
    sort(v.begin(), v.end());
    // forn(i, 0, m) cout << v[i].first << " \n"[i==m-1];
    ll a = -1, b = m;
    forn(i, 0, n) {
        if (!(i&1)) {
            a++;
            b--;

            cout << v[a].second << " " << v[b].second << " "; 
            cout << v[a].second << " " << v[b].second << " "; 
            cout << v[a].second << " " << v[b].second << ln; 
        } else {
            cout << v[b].second << " " << v[a].second << " "; 
            cout << v[b].second << " " << v[a].second << " "; 
            cout << v[b].second << " " << v[a].second << ln; 
        }
    }

}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}