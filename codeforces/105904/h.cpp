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
	vector<ll> bit;
	BIT(ll _n=0) : n(_n), bit(n + 1) {}
	BIT(v64& v) : n(v.size()), bit(n + 1) {
		for (ll i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			ll j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(ll i, ll x) {
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(ll i) {
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(ll l, ll r) {
		return pref(r) - pref(l - 1); 
	}
	ll upper_bound(ll x) {
		ll p = 0;
		for (ll i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
    ll esquisita(ll l, ll r, ll offset) {
        l = (l+offset) % n;
        r = (r+offset) % n;
        if (l <= r) return query(l, r);
        else return query(l, n-1) + query(0, r);
    }
};

int main(){
    _;
    ll q, k; cin >> q >> k;
    v64 v(k);
    iota(v.begin(), v.end(), 0);
    BIT bit(v);
    const ll tot_sum = bit.query(0, k-1);

    ll offset = 0;
    forn(kk, 0, q) {
        ll t; cin >> t;

        if (t == 1) {
            ll x; cin >> x;
            offset = (offset + x) % k;

        } else if (t == 2) {
            ll a, b; cin >> a >> b;
            
            a = (a+offset) % k;
            b = (b+offset) % k;
            
            ll va = bit.query(a,a);
            ll vb = bit.query(b,b);
            
            bit.update(a, vb-va);
            bit.update(b, va-vb);
        } else if (t == 3) {
            ll l, r; cin >> l >> r;

            ll lb = l/k;
            ll rb = r/k;

            if (lb == rb) {
                cout << ((r - l + 1) * lb * k + bit.esquisita(l % k, r % k, offset)) << ln;
                continue;
            }

            ll suff = (k - (l%k))*(lb*k) + bit.esquisita(l%k, k-1, offset);
            ll pref = ((r%k) + 1)*(rb*k) + bit.esquisita(0, r%k, offset);
            
            ll nblk = rb - lb - 1;
            if (nblk < 0) nblk = 0;
            
            ll midway = k*k* (lb + rb) * nblk/2 + tot_sum * nblk;
            
            cout << suff + midway + pref << ln;
        }
    }

    return 0;
}