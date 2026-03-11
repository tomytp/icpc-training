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

inline ll calc(ll x) {
    return (x+1) / 2;
}

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    v64 blocks;
    ll cur_block = 1;
    forn(i, 1, n) {
        if (v[i] == v[i-1]) continue;
        if (v[i]-1 <= v[i-1]) cur_block++;
        else {
            blocks.push_back(cur_block);
            cur_block = 1;
        }
    }
    if (cur_block) blocks.push_back(cur_block);

    ll ans = 0;
    for (auto block : blocks) {
        ans += calc(block);
    }
    debug(blocks.size());
    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}