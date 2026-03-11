#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1'000'000'007;
const ll MAXN = 1'000'008;

template<int p> struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if(e % 2) ret = ret * b % p;
            e /= 2, b = b* b % p;
        }
        return ret;
    }
    ll inv(ll b) {
        return expo(b, p-2);
    }

    using m = mod_int;
    ll v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
        if(v_ >= p or v_ <= -p) v_ %= p;
        if(v_ < 0) v_ += p;
        v = v_;
    }

    m& operator += (const m& a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m& operator -=(const m& a) {
        v -= a.v;
        if(v < 0) v += p;
        return *this;
    }
    m& operator *= (const m& a) {
        v = v * ll(a.v) % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }

    m operator -(){ return m(-v); }
    m& operator ^=(ll e) {
        if(e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        return *this;
    }
    bool operator ==(const m& a){ return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }

    friend ostream& operator <<(ostream& out, m a) {
        return out << a.v;
    }

    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, m b) { return a ^= b; }
};
typedef mod_int<MOD> mint;

vector<mint> inv_fact(MAXN);
vector<mint> fact(MAXN);

void calc(){
    inv_fact[0] = 1;
    fact[0] = 1;
    forn(i, 1, MAXN){
        fact[i] = fact[i-1]*i;
        inv_fact[i] = inv_fact[i-1]/i;
    }
}

int main() {
    _; ll n, q; cin >> n >> q;
    ll in_order = 0;
    v64 v(n);
    map<ll, ll> f;
    forn(i, 0, n){
        cin >> v[i];
        f[v[i]]++;
    }

    forn(i, 0, n){
        if(i == 0 || v[i-1] <= v[i]) in_order++;
    }

    calc();
    mint p = inv_fact[n];
    for(auto x : f){ 
        debug(x.second);
        p *= fact[x.second]; 
    }

    debug(in_order);
    // if(in_order == n) cout << 1 << ln;
    // else cout << p << ln;

    cout << p << ln;

    forn(i, 0, q){
        ll ind, val; cin >> ind >> val;
        ind--;
        p/= f[v[ind]];
        f[v[ind]]--;

        if(ind == 0 || v[ind-1] <= v[ind]) in_order--;
        if(ind != n-1 && v[ind] <= v[ind+1]) in_order--;

        v[ind] = val;

        if(ind == 0 || v[ind-1] <= v[ind]) in_order++;
        if(ind != n-1 && v[ind] <= v[ind+1]) in_order++;

        f[v[ind]]++;
        p*= f[v[ind]];

        debug(in_order);
        // if(in_order == n) cout << 1 << ln;
        // else cout << p << ln;

        cout << p << ln;
    } 
    return 0;
}