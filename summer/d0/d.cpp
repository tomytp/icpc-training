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

// Modular Integer
//
// Fixed-modulus integer type with +, -, *, /, and exponentiation; modulo should be prime for division via Fermat.
//
// complexity: O(1) per arithmetic op (O(log E) for exponentiation), O(1)

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


int main(){
    _;
    ll n; cin >> n;
    vector<mint> a(n), b(n-1);

    forn(i,0,n) cin >> a[i];
    forn(i,0,n-1) cin >> b[i];

    if(n == 1){
        ll q; cin >> q;
        forn(i,0,q){
            ll l;
            cin >> l >> l;
            cout << a[0] << ln;
        }

        return 0;
    }

    vector<mint> day(n);

    day[0] = a[0];

    forn(i,1,n){
        day[i] = day[i-1]*b[i-1] + a[i];
    }

    vector<mint> mult(n-1);

    mult[0] = b[0];
    
    forn(i,1,n-1){
        mult[i] = mult[i-1]*b[i];
    }

    auto accmult = [&](ll l, ll r){
        if(l == 0) return mult[r];
        return mult[r]/mult[l-1];
    };

    ll q; cin >> q;
    forn(i,0,q){

        ll l, r;
        cin >> l >> r;
        l--, r--;

        if(l == 0){
            cout << day[r] << ln;
            continue;
        }

        mint resp = 0;
        resp += day[r];
        mint sub = day[l-1];

        sub *= accmult(l-1, r-1);

        resp -= sub;
        cout << resp << ln;
    }

    return 0;
}