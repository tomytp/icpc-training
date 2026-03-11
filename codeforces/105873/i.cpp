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

void merge(map<ll, ll> &a, map<ll, ll>& b) {
    if (b.size() > a.size()) {
        swap(a, b);
    }

    for (auto &[k, v]: b) {
        a[k] += v;
    }
}

map<p64, ll> ans;

map<ll, ll> dfs(ll u, ll p, vector<v64>& g, v64& top, set<p64>& queries) {
    map<ll, ll> a;
    a[top[u]] = 1;

    for (auto v : g[u]) {
        if (v == p) continue;
        
        auto b = dfs(v, u, g, top, queries);
        merge(a, b);
    }

    auto it = queries.lower_bound({u, -10000});

    while (it != queries.end() && it->first == u) {
        ans[*it] = a[it->second];
        it++;
    }

    return a;
}

int main(){
    _;
    ll n, q; cin >> n >> q;
    v64 topic(n); forn(i, 0, n) cin >> topic[i];
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    set<p64> queries;
    vector<p64> q2(q);
    forn(i, 0, q) {
        ll x, k; cin >> x >> k;
        x--;
        queries.emplace(x, k);
        q2[i] = {x, k};
    }

    dfs(0, -1, g, topic, queries);

    forn(i, 0, q) {
        cout << ans[q2[i]] << ln;
    }

    return 0;
}