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

int main() {
    _;
    ll n, m, k; cin >> n >> m >> k;
    vector<v64> g(n), g2(n), ag(n);
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<ll> q;
    q.push(0);
    v64 h(n, INF), vis(n);
    h[0] = 0;
    vis[0] = 1;

    while (q.size()) {
        ll u = q.front(); q.pop();
        for (auto v : g[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = 1;
            h[v] = h[u] + 1;
        }
    }

    queue<ll> q2;
    q2.push(n-1);
    v64 rh(n, INF), rvis(n);
    rh[n-1] = 0;
    rvis[n-1] = 1;

    while (q2.size()) {
        ll u = q2.front(); q2.pop();
        for (auto v : g[u]) {
            if (rvis[v]) continue;
            q2.push(v);
            rvis[v] = 1;
            rh[v] = rh[u] + 1;
        }
    }

    v64 indeg(n), outdeg(n);
    v64 rel(n), freq(n);
    forn(u, 0, n) {
        for(auto v : g[u]) {
            if (h[u] != h[v]-1) continue;
            if (u != n-1 && h[u] >= h[n-1]) continue;
            if (v != n-1 && h[v] >= h[n-1]) continue;
            if (h[u] + rh[v] != h[n-1] - 1) continue;
            if (!rel[u]) freq[h[u]]++;
            if (!rel[v]) freq[h[v]]++;
            rel[u]++;
            rel[v]++;
            indeg[v]++;
            g2[u].push_back(v);
            ag[v].push_back(u);
            outdeg[u]++;
        }
    }

    swap(g2, g);

    ll crit = 0;

    if (h[n-1] == INF) {
        cout << -1 << " ";
        forn(i, 0, k) {
            ll x; cin >> x; 
            cout << -1 << " ";

        }
        cout << ln;
        return 0;
    }

    forn(i, 0, h[n-1] + 1) {
        if (freq[i] == 1) crit++;
    }

    crit -= 2;
    bool broken = false;
    vector<bool> rem(n);

    function<void (ll u, ll p)> dfs = [&](ll u, ll p) {
        if (rem[u]) return;

        rem[u] = true;
        if (broken) return;
        if (h[u] == INF || !rel[u]) {
            return;
        }
        if (freq[h[u]] == 1 && u != n-1 && u != 0) {
            broken = true;
            return;
        }

        freq[h[u]]--;
        if (freq[h[u]] == 1) crit++;
        for (auto v : g[u]) {
            indeg[v]--;
            if (indeg[v] > 0 || rem[v]) continue; 
            dfs(v, 5);
        }
    };

    function<void (ll u, ll p)> dfs2 = [&](ll u, ll p) {
        rem[u] = true;
        if (broken) return;
        if (h[u] == INF || !rel[u]) {
            return;
        }
        if (p != -1 && freq[h[u]] == 1 && u != n-1 && u != 0) {
            broken = true;
            return;
        }
        if(p != -1){
            freq[h[u]]--;
            if (freq[h[u]] == 1) crit++; 
        }
        for (auto v : ag[u]) {
            outdeg[v]--;
            if (outdeg[v] > 0 || rem[v]) continue; 
            dfs2(v, 5);
        }
    };

    cout << crit << " "; 
    forn(i, 0, k) {
        ll c; cin >> c;
        c--;

        if (!rem[c]) {
            dfs(c, -1);
            dfs2(c, -1);
        }

        if (broken) {
            cout << -1 << " ";
        } else {
            cout << crit << " ";
        }

    }
    cout << ln;



    return 0;
}