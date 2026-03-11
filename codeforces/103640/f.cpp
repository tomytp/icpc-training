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

int main() {
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll ct = 1;
    vector<bool> vis(n);
    vector<ll> comp(n);
    v64 tams = {n-1};
    vis[n-1] = true;
    ll curr = 1;
    ll mx = 0;
    function<void (ll)> dfs = [&](ll u) {
        vis[u] = true;
        comp[u] = curr;
        ct++;
        mx = max(u, mx); 

        for (auto v : g[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
    };

    forn(i, 0, n) {
        if (!vis[i]) {
            mx = 0;
            dfs(i);
            tams.push_back(mx);
            curr++;
        }
    }

    debug(tams.size()); 

    if (tams.size() == 2) {
        forn(i, 0, n-1) cout << "B";
        cout << "A" << ln;
        return 0;
    }

    v64 owner(n);
    forn(i, 0, tams.size()) {
        if (tams[i] != n-2) continue;
        forn(j, 0, n) {
            if (comp[j] == i) owner[j] = 1;
        }
    }

    forn(i,0 , n) {
        if (owner[i]) cout << "B";
        else cout << "A";
    }
    cout << ln;

    return 0;
}