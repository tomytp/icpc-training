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

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct sat {
    ll n, tot;
    vector<v64> g;
    v64 vis, comp, id, ans;
    stack<ll> s;

    sat() {}
    sat(ll n_) : n(n_), tot(n), g(2*n) {}

    ll dfs(ll i, ll& t) {
        ll lo = id[i] = t++;
        s.push(i), vis[i] = 2;
        for (ll j : g[i]) {
            if (!vis[j]) lo = min(lo, dfs(j, t));
            else if (vis[j] == 2) lo = min(lo, id[j]);
        }
        if (lo == id[i]) while (1) {
            ll u = s.top(); s.pop();
            vis[u] = 1, comp[u] = i;
            if ((u>>1) < n and ans[u>>1] == -1) ans[u>>1] = ~u&1;
            if (u == i) break;
        }
        return lo;
    }

    void add_impl(ll x, ll y) { // x -> y = !x ou y
        x = x >= 0 ? 2*x : -2*x-1;
        y = y >= 0 ? 2*y : -2*y-1;
        g[x].push_back(y);
        g[y^1].push_back(x^1);
    }
    void add_cl(ll x, ll y) { // x ou y
        add_impl(~x, y);
    }
    void add_xor(ll x, ll y) { // x xor y
        add_cl(x, y), add_cl(~x, ~y);
    }
    void add_eq(ll x, ll y) { // x = y
        add_xor(~x, y);
    }
    void add_true(ll x) { // x = T
        add_impl(~x, x);
    }
    void at_most_one(v64 v) { // no max um verdadeiro
        g.resize(2*(tot+v.size()));
        for (ll i = 0; i < v.size(); i++) {
            add_impl(tot+i, ~v[i]);
            if (i) {
                add_impl(tot+i, tot+i-1);
                add_impl(v[i], tot+i-1);
            }
        }
        tot += v.size();
    }

    pair<bool, v64> solve() {
        ans = v64(n, -1);
        ll t = 0;
        vis = comp = id = v64(2*tot, 0);
        for (ll i = 0; i < 2*tot; i++) if (!vis[i]) dfs(i, t);
        for (ll i = 0; i < tot; i++)
            if (comp[2*i] == comp[2*i+1]) return {false, {}};
        return {true, ans};
    }
};

vector<v64> g;
v64 parent;

void dfs_parent(ll u, ll p) {
    parent[u] = p;
    debug(u);
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs_parent(v, u);
    }
}

pair<bool, v64> solve_with_root(ll r, ll n, ll N, const vector<v64>& pos_by_color) {
    parent.assign(N, -1);
    dfs_parent(r, -1);

    sat s(N); 

    forn(c, 0, n) {
        s.add_xor(pos_by_color[c][0], pos_by_color[c][1]); 
    }

    forn(i, 0, N) 
        if (i != r)
             s.add_impl(i, parent[i]);

    s.add_true(r);
    return s.solve();
}

bool print_solution(bool possible, const v64& ans, ll n, ll N) {
    if (!possible) return false;

    v64 result_nodes;
    forn(i, 0, N) 
        if (ans[i])
            result_nodes.push_back(i + 1);

    forn(i, 0, n) cout << result_nodes[i] << (i == n - 1 ? "" : " ");
    cout << ln;
    return true;
}

void solve(){
    ll n; cin >> n;
    ll n2 = 2 * n;

    vector<v64> pos_by_color(n);
    v64 color(n2);
    forn(i, 0, n2) {
        cin >> color[i];
        color[i]--;
        pos_by_color[color[i]].push_back(i);
    }

    g.clear();
    parent.clear();
    g.resize(n2);
    forn(i, 0, n2-1) {
        ll u, v; cin >> u >> v;
        u--, v--; 
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll root1 = pos_by_color[0][0];
    ll root2 = pos_by_color[0][1];

    auto [possible1, ans1] = solve_with_root(root1, n, n2, pos_by_color);
    if (print_solution(possible1, ans1, n, n2)) {
        return;
    }

    auto [possible2, ans2] = solve_with_root(root2, n, n2, pos_by_color);
    if (print_solution(possible2, ans2, n, n2)) {
        return;
    }

    cout << -1 << ln; 
    return;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
}