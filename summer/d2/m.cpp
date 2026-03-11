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
    ll n, k;
    cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    mint curr = 0, num = 0;
    forn(i, 0, n) num += v[i]*((mint)k^(n-1-i));
    ll fix_dig = 0;
    set<ll> used;
    forn(i, 0, n){
        if(fix_dig == i) used.insert(v[i]);
        while(fix_dig < n && used.count(v[fix_dig])){
            curr += v[fix_dig]*((mint)k ^ (n-1-fix_dig));
            fix_dig++;
        }

        if(fix_dig == n){
            cout << 0 << ln;
            continue;
        }

        mint resp = curr;
        ll wrong_dig = v[fix_dig], wrong_up = -1, wrong_down = -1;
        auto it = lower_bound(used.begin(), used.end(), wrong_dig);
        if(it != used.end()) wrong_up = *it;
        if(it != used.begin()) wrong_down = *prev(it);
        
        if(wrong_up - wrong_dig == wrong_dig - wrong_down){
            ll max_dig = *used.rbegin();
            ll min_dig = *used.begin();

            if(min_dig <= (k-1)-max_dig){

            }
        }

        if(wrong_down == -1 || wrong_up - wrong_dig < wrong_dig - wrong_down){
            ll min_dig = *used.begin();
            ll num_dig = n-1-fix_dig;
            resp += wrong_up*((mint)k ^ num_dig);
            mint ones = (mint)k^num_dig -1;
            ones /= (k-1);
            resp += min_dig*ones;

            cout << resp - num << ln;
        }

        if(wrong_up == -1 || wrong_up - wrong_dig > wrong_dig - wrong_down){
            ll max_dig = *used.rbegin();
            ll num_dig = n-1-fix_dig;

            resp += wrong_down*((mint)k ^ num_dig);
            mint ones = (mint)k^num_dig -1;
            ones /= (k-1);
            resp += max_dig*ones;

            cout << num - resp << ln;
        }

    }
    return 0;
}