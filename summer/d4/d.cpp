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

mint any_even(ll k){
    if(k < 0) return 0;
    return ((mint)4)^k;
}

mint any_even_begin(ll k) {
    if(k == 0) return 1;
    return mint(3)*any_even(k-1);
}

mint any_trio(ll k){
    if(k < 0) return 0;
    return ((mint)3)^k;
}

mint any_trio_begin(ll k){
    if(k == 0) return 1;
    return mint(2)*any_trio(k-1);
}

int main(){
    _; ll n; cin >> n;
    mint resp = any_even_begin(n);
    mint n1n9 = resp;
    debug(n1n9);

    // agora, fazemos o caso em que existe um 1

    // (vazio)1 (qualquer par)
    resp += any_even(n-1);

    // 91 (qualquer par)
    resp += any_even(n-2);

    // 901 (qualquer par)
    resp += any_even(n-3);

    // 9081 (qualquer par)
    resp += any_even(n-4);

    // 9081 (qualquer par)
    resp += any_even(n-4);

    // 981 (qualquer par)
    resp += any_even(n-3);

    // 8 0(k vezes) 1 (qualquer par)
    forn(k, 0, n-1) resp += any_even(n-2-k);

    mint s1 = resp - n1n9;
    debug(s1);

    // agora, fazemos o caso em que nao existe um 1

    // se nao temos 4 a esquerda do 9
    // escolho a posicao do 9, any_even pra frente, any_trio_begin para tras
    forn(i, 0, n) resp += any_trio_begin(i)*any_even(n-1-i);

    // agora, temos um 4
    // se temos 6 entre 4 e 9
    // (vazio) 4 6(k vezes) 9
    forn(k, 1, n-1) resp += any_even(n-2-k);

    // 94 6(k vezes) 9
    forn(k, 1, 3) resp += any_even(n-3-k); // se der merda conceitual, provavelmete foi aqui

    // agora, nao temos 6 entre 4 e 9
    // 949 
    resp += any_even(n-3);

    // 49
    resp += any_even(n-2);

    // 6(k1 vezes) 0(k2 vezes) 49
    set<p64> prob = {
        {2,4},
        {3,4},
        {3,3}
    };

    forn(k1, 1, 4)
    forn(k2, 0, 5){
        if(prob.count({k1,k2})) continue;
        resp += any_even(n-k1-k2-2);
    }
    
    

    mint n1s9 = resp - s1 - n1n9;
    debug(n1s9);
    cout << resp << ln;

    return 0;
} 