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
    ll n; cin >> n;
    vector<p64> v(n); 
    forn(i, 0, n) cin >> v[i].first, v[i].second = i;
    sort(v.begin(), v.end());

    dsu sdu(n);
    vector<p64> pos(n);
    forn(i, 0, n) {
        sdu.uni(i, v[i].second);
        pos[i] = {i, v[i].second};
    }
    map<ll, v64> groups;
    forn(i, 0, n) {
        groups[sdu.find(i)].push_back(i);
    }

    cout << groups.size() << ln;
    for (auto& [k, vec] : groups) {
        cout << vec.size();
        for (auto x : vec) cout << " " << x + 1;
        cout << ln;
    }

    return 0;
}