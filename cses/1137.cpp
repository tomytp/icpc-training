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

struct Bit {
	ll n;
	v64 bit;
	Bit(ll _n=0) : n(_n), bit(n + 1) {}
	Bit(v64& v) : n(v.size()), bit(n + 1) {
		for (ll i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			ll j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(ll i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(ll i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(ll l, ll r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	ll upper_bound(ll x) {
		ll p = 0;
		for (ll i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};


int main(){
    _;
    ll n, q; cin >> n >> q;
    vector<v64> g(n);
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    v64 to_bit;
    vector<p64> idx(n);
    function<void (ll, ll)> dfs = [&](ll u, ll p) {
        idx[u].first = to_bit.size();
        to_bit.push_back(v[u]);

        for (auto k : g[u]) {
            if (k == p) continue;
            dfs(k, u);
        }

        idx[u].second = to_bit.size();
        to_bit.push_back(v[u]);
    };
    
    dfs(0, -1);
    Bit bit(to_bit);

    forn(i, 0, q) {
        ll type; cin >> type;
        if (type == 1) {
            ll s, x; cin >> s >> x;
            s--;
            bit.update(idx[s].first, x - bit.query(idx[s].first, idx[s].first));
            bit.update(idx[s].second, x - bit.query(idx[s].second, idx[s].second));
        } else {
            ll s; cin >> s;
            s--;
            cout << bit.query(idx[s].first, idx[s].second) / 2 << ln;
        }
    }

    return 0;
}
