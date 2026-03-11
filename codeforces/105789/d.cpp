#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct comp {
    vector<p64> mp;
    ll off = 0;

    comp(ll i, ll cost) {
        mp.emplace_back(i, cost);
    }
    comp() {}

    void merge(comp& o, ll v) {
        if (mp.size() < o.mp.size()) {
            swap(mp, o.mp);
            swap(off, o.off);
        }

        off += v * (ll)o.mp.size();
        o.off += v * (ll) mp.size();

        for (auto& [key, val] : o.mp) {
            mp.emplace_back(key, val + o.off - off);
        }
    }
};

struct dsu {
    v64 id, sz;
    vector<comp> comps;

    dsu(ll n, v64& costs) : id(n), sz(n, 1) {
        iota(id.begin(), id.end(), 0);
        comps.resize(n);
        forn(i, 0, n) {
            comps[i] = comp(i, costs[i]);
        }
    }
    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b, ll cost) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
        comps[a].merge(comps[b], cost);
    }
};



int main() {
    _;
    ll n, m; cin >> n >> m;
    v64 cost(n);
    forn(i, 0, n) cin >> cost[i];

    vector<v64> edges(m);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--, b--;
        edges[i] = {max(cost[a], cost[b]), a, b};
    }

    dsu sdu(n, cost);

    for (auto& x : edges) {
        sdu.uni(x[1], x[2], x[0]);
    }

    auto& voce = sdu.comps[sdu.find(0)];
    sort(voce.mp.begin(), voce.mp.end());
    for (auto& [k, val] : voce.mp) {
        cout << val + voce.off << " ";
    }
    cout << ln;

    return 0;
}