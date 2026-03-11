#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(ll n, ll k, ll m) {
    vector<ll> keys(n, -1);
    vector<bool> open(n, true);
    forn(i, 0, k) {
        ll a, b; cin >> a >> b;
        a--, b--;
        open[b] = false;
        keys[a] = b;
    }

    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<ll> q;
    vector<bool> vis(n);
    q.push(0);
    while (q.size()) {
        ll u = q.front();
        q.pop();
        vis[u] = true;

        if (keys[u] != -1) {
            open[keys[u]] = true;
            if (vis[keys[u]]) q.push(keys[u]);
        }
        
        for (auto v : g[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            if (!open[v]) continue;
            q.push(v);
        }
    }


    if (vis[n-1]) cout << "Y\n";
    else cout << "N\n";

}

int main() {
    _;
    ll n, k, m; cin >> n >> k >> m;
    while (n != -1) {
        solve(n, k, m);
        cin >> n >> k >> m;
    }
    return 0;
}
