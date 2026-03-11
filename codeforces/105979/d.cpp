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

struct dsu {
	vector<ll> id, sz;

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 en(n);
    map<ll, v64> cities_by_starting;

    forn(i, 0, n) cin >> en[i], cities_by_starting[en[i]].push_back(i);
    
    map<ll, vector<p64>> edges_by_starting;
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        edges_by_starting[max(en[a], en[b])].push_back({a, b});
    }

    dsu sdu(n);
    v64 ans(n);
    for (auto& [st, cities] : cities_by_starting) {
        for (auto& [a, b]: edges_by_starting[st]) {
            sdu.uni(a, b);
        }

        for (auto& city: cities) {
            debug(city);
            debug(sdu.sz[sdu.find(city)]);
            ans[city] = sdu.sz[sdu.find(city)];
        }
    }

    forn(i, 0, n) cout << ans[i] << ln;

    return 0;
}