#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> vis(n), dep(n);
    function<void(int, int, int)> del = [&](int u, int p, int d) {
        if(d <= 0) {
            vis[u] = 1;
        } else {
            dep[u] = d;
        }
        for(int nxt: g[u]) {
            if(!vis[nxt] && nxt != p) {
                del(nxt, u, d - 1);
            }
        }
    };
    auto arruma = [&](int u, int p, int d) {
        dep[u] = d + 1;
        for(int nxt : g[u]) {
            if(!vis[nxt] && nxt != p) {
                del(nxt, u, d);
            }
        }
    };
    function<void(int, int)> dfs = [&](int u, int p) {
        vector<int> v;
        for(int nxt : g[u]) {
            if(nxt != p) {
                v.emplace_back(nxt);
                dfs(nxt, u);
            }
        }
        if(v.empty()) {
            dep[u] = 1;
            return;
        }
        int dep1 = dep[v[0]], dep2 = 0;
        if((int) v.size() == 2) {
            dep2 = dep[v[1]];
        }
        // cerr << u << ' ' << dep1 << ' ' << dep2 << '\n';
        if(dep1 - dep2 > 1) {
            arruma(v[0], u, dep2);
        } else if(dep2 - dep1 > 1) {
            arruma(v[1], u, dep1);
        }
        dep[u] = dep[v[0]];
        if((int) v.size() == 2) {
            dep[u] = max(dep[u], dep[v[1]]);
        }
        dep[u]++;
    };
    dfs(0, -1);
    cout << accumulate(vis.begin(), vis.end(), 0) << '\n';
    return 0;
}
