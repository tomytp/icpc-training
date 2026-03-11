#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n; cin >> n;

    vector<string> g(n);
    forn(i, 0, n) cin >> g[i];
    
    vector<bool> visited(n);
    vector<p64> ans;
    function<void (ll)> dfs = [&](ll u) {
        visited[u] = true;

        forn(i, 0, n) {
            if (!visited[i] && (g[u][i] != '0')) {
                ans.push_back({u, i});
                dfs(i);
            }
        }
    };
    dfs(0);
    if (ans.size() != n-1) {
        cout << "No" << ln << ln;
        return;
    }

    cout << "Yes" << ln;
    for (ll i = n-2; i >= 0 ; i--) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << ln;
    }
    cout << ln;

}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}