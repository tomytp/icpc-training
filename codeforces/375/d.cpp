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

struct BIT {
	ll n;
	v64 bit;
	BIT(ll _n=0) : n(_n), bit(n + 1) {}
	BIT(v64& v) : n(v.size()), bit(n + 1) {
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
		for (i++; i; i -= i & -i) {
			ret += bit[i];
		}
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


struct qr {
	ll l, r, k;
};

const ll MAX = 2e5+10;
const ll SQ = sqrt(MAX);
ll n, mm; 
BIT bit;
v64 mp(MAX);
v64 c;
v64 vec;

inline void insert(ll p) {
	debug(p);
	auto color = vec[p];
	auto& oc = mp[color];
	bit.update(oc, -1);
	oc++;
	bit.update(oc, 1);
}

inline void erase(ll p) {
	debug(p);
	auto color = vec[p];
	auto& oc = mp[color];
	debug(oc);
	bit.update(oc, -1);
	oc--;
	bit.update(oc, 1);
}

inline ll hilbert(ll x, ll y) {
	static ll N = 1 << (sizeof(ll)*8 - __builtin_clzll(MAX));
	ll rx, ry, s;
	ll d = 0;
	for (s = N/2; s > 0; s /= 2) {
		rx = (x & s) > 0, ry = (y & s) > 0;
		d += s * ll(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) x = N-1 - x, y = N-1 - y;
			swap(x, y);
		}
	}
	return d;
}

#define HILBERT true
vector<ll> MO(vector<qr> &q) {
	ll m = q.size();
	vector<ll> ord(m);
	iota(ord.begin(), ord.end(), 0);
#if HILBERT
	vector<ll> h(m);
	for (ll i = 0; i < m; i++) h[i] = hilbert(q[i].l, q[i].r);
	sort(ord.begin(), ord.end(), [&](ll l, ll r) { return h[l] < h[r]; });
#else
	sort(ord.begin(), ord.end(), [&](ll l, ll r) {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second;
	});
#endif
	vector<ll> ret(m);
	ll l = 0, r = -1;

	for (ll i : ord) {
		ll ql = q[i].l, qr = q[i].r, qk = q[i].k;
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		if (qk <= n) ret[i] = bit.query(2*qk, 2*n+1);
		else ret[i] = 0;
	}
	return ret;
}


int main(){
    _;
    cin >> n >> mm;
    c.resize(n);
    forn(i, 0, n) cin >> c[i];
    vector<v64> g(n);
	bit = BIT(n * 2 + 2);
	bit.update(0, MAX);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<p64> points(n);
    function<void (ll, ll)> dfs = [&](ll u, ll p) -> void {
        points[u].first = vec.size();
        vec.push_back(c[u]);

        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
        }

        points[u].second = vec.size();
        vec.push_back(c[u]);
    };

	dfs(0, -1);
    vector<qr> queries(mm);
    forn(i, 0, mm) {
        ll v, k; cin >> v >> k;
        v--;
		queries[i] = {points[v].first, points[v].second, k};
    }

	auto resp = MO(queries);
	for (auto x : resp) cout << x << ln;

    return 0;
}