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
const ll MAXK = 100'005;

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

struct quad{
    mint x, y;
    using m = quad;
    quad() : x(0), y(0) {}
    quad(ll x_) : x(x_), y(0) {}
    quad(mint x_, mint y_) {
        x = x_;
        y = y_;
    }

    m& operator += (const m& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    m& operator -=(const m& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    
    m& operator *= (const m& a) {
        x = x*a.x + 5*y*a.y;
        y = x*a.y + y*a.x; 
        return *this;
    }

    m inv(quad q){
        mint dem = x*x-5*y*y;
        return quad(q.x/dem, (-q.y)/dem); 
    }
    
    m operator /=(const m& a) {
        return *this*inv(a);
    }

    // m operator -(){ return quad(-this->x, -this->y); }
    
    m expo(quad b, ll e){
        quad ret = quad(1,0);

        while (e) {
            if(e % 2) ret = ret * b ;
            e /= 2, b = b* b;
        }
        return ret;
    }

    m operator ^=(ll e) {
        quad aux = *this;
        if(e < 0) {
            aux = inv(aux);
            e = -e;
        }
        aux = expo(aux, e);
        return aux;
    }
    
    // bool operator ==(const m& a){ return v == a.v; }
    // bool operator !=(const m& a) { return v != a.v; }
    
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll b) { return a ^= b; }
};

vector<quad> fact(MAXK), invfact(MAXK), binom(MAXK);

void calc(ll k){
    fact[0] = 1;
    invfact[0] = 1;
    forn(i,1,k+1){
        fact[i] = fact[i-1]*i;
        invfact[i] = invfact[i-1]/i;
    }
    forn(i,0,k+1){
        binom[i] = fact[k]*invfact[i]*invfact[k-i];
    }
}

int main() {
    _; 
    ll n, k; 
    cin >> n >> k;
    quad phi(1/mint(2), 1/mint(2));
    
    calc(k);

    quad gama = phi^k, theta = phi^(-2);
    quad alpha = gama^(n+1), beta = theta^(n+1);

    trace(
        cout << phi.x << " " << phi.y << ln;
        cout << alpha.x << " " << alpha.y << ln;
        cout << beta.x << " " << beta.y << ln;
        cout << gama.x << " " << gama.y << ln;
        cout << theta.x << " " << theta.y << ln;
        cout << ln;
    );

    quad resp = 0;
    quad pow1 = alpha;
    quad pow2 = gama;
    
    forn(i,0,k){
        quad aux = (pow1 - 1)/(pow2 - 1);
        aux *= binom[i];

        resp += aux;
        trace(
            cout << pow1.x << " " << pow1.y << ln;
            cout << pow2.x << " " << pow2.y << ln;
            cout << binom[i].x << " " << binom[i].y << ln;
            cout << resp.x << " " << resp.y << ln;
            cout << ln;
        );
        pow1 *= beta;
        pow2 *= theta;
    }

    auto aux = quad(0,1/mint(5)); 
    aux ^= k;

    trace(
        cout << "------------" << ln;
        cout << aux.x << " " << aux.y << ln;
        cout << resp.x << " " << resp.y << ln;
    );

    resp *= aux;
    cout << resp.x << ln;
    cout << resp.y << ln;
    return 0;
}