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
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 open;
    vector<bool> ans(n+1);
    forn(i, 0, n) {
        for (auto& o : open) {
            o += v[i];
            if (o > n) continue;
            ans[o] = true;
        }
        open.push_back(v[i]);
    }

    ll res = 0;
    forn(i, 0, n) {
        if (ans[v[i]]) {
            res++;
        }
    }
    cout << res << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}