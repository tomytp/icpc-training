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
    v64 inicial(n), final(n);
    forn(i, 0, n) cin >> final[i];
    forn(i, 0, n) cin >> inicial[i];
    map<ll, ll> mp;
    forn(i, 0, n) {
        if (mp.count(inicial[i]) && mp[inicial[i]] != final[i]) {
            cout << -1 << ln;
            return;
        }
        mp[inicial[i]] = final[i];
    }

    ll curr_max = 0; 
    ll dest = 0;
    for (auto& [st, ed]: mp) {
        if (ed > st - curr_max) {
            cout << -1 << ln;
            return;
        }
        if (ed < dest) {
            cout << -1 << ln;
            return;
        }
        curr_max = st - ed;
        dest = ed;
    }    
    cout << curr_max << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}