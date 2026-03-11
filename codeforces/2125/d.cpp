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

const ll MOD = 998244353;

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	ll v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<MOD> mint;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct seg {
    ll l, r;
    mint w;
};

int main(){
    _;
    ll n, m; cin >> n >> m;

    vector<seg> segs;
    segs.reserve(n);

    mint tot_prob = 1;

    forn(i, 0, n){
        ll l, r, p, q;
        cin >> l >> r >> p >> q;

        segs.push_back({l, r, mint(p) / mint(q - p)});
        tot_prob *= mint(q - p) / mint(q);
    }

    sort(segs.begin(), segs.end(), [](const seg& a, const seg& b){ return a.r < b.r; });

    vector<mint> dp(m + 1);
    dp[0] = 1;

    ll idx = 0;
    forn(pos, 1, m + 1){
        mint cur = 0;
        while(idx < n && segs[idx].r == pos){
            cur += dp[segs[idx].l - 1] * segs[idx].w;
            idx++;
        }
        dp[pos] = cur;
    }

    cout << dp[m] * tot_prob << ln;
    return 0;
}