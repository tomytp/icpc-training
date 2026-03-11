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
const ll MOD = 998244353;

template<ll p> struct mod_int {
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
        v = v * a.v % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -() const { return m(-v); }
    m& operator ^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        // possible optimization:
        // careful with 0^0
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


void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<mint> p2(n);
    p2[0] = 1;
    forn(i, 1, n) p2[i] = 2*p2[i-1];
    v64 pref(n);
    pref[0] = (s[0] == '(') ? 1 : -1;
    forn(i, 1, n) pref[i] = pref[i-1] + ((s[i] == '(') ? 1 : -1); 
    mint ans = n;
    forn(i, 1, n) {
        if (s[i] == '(') {
            ans += p2[i] - 1;
        }
    }

    vector<mint> prefopen(n + 1, 0);
    mint sum_close = 0;
    ll llow = 0;
    
    forn(j, 0, n) {
        ll llowj = llow;
        mint valj = 1 + sum_close + (prefopen[j-1] - prefopen[llowj]);
        
        if (s[j] == '(') {
            prefopen[j] = prefopen[j-1] + valj;
        } else {
            prefopen[j] = prefopen[j-1];
            ans += valj - 1;
            sum_close += valj;
        }
        
        if (pref[j] < 2) llow = j;
    }

    cout << ans << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
