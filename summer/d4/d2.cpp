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

// Linear Sieve (prime precomputation)
//
// Computes primes up to N in O(N) using the smallest prime factor (lp).
// pr will contain all primes <= N.
// lp[x] stores the smallest prime dividing x.
//
// complexity: O(N)
// escrito pelo gpt, cuidado

const ll N = 100'000'010;
v64 lp(N+1), pr;

void sieve(){
    forn(i, 2, N+1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

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

    sieve();

    set<ll> prob;
    for(ll p : pr) prob.insert(p);

    forn(i,0,N){
        ll pot = 1;
        bool pode = true;
        while(pot <= i){
            ll menor = i%pot;
            ll maior = i/pot;
            maior /= 10;
            ll tenta = menor + maior*pot;
            pot *= 10;
            if(prob.count(tenta)) pode = false;
        }
        if(!pode) prob.insert(i);
    }

    ll cnt = 0;
    set<ll> pots = {1,10,100,1000,10'000, 100'000,1'000'000,10'000'000};
    ll last = 0;

    map<string, ll> mp;
    map<string, ll> lastmp;
    // "n1s9"
    // "s1"
    // "n1n9"
    forn(i,0,N){
        if(prob.count(i)) continue;
        cnt++;

        v64 freq(10);

        ll test_p = i;
        while(test_p > 0){
            freq[test_p%10]++;
            test_p/=10;
        }
        if(freq[1] == 0){
            if(freq[9] == 0){
                mp["n1n9"]++;
            }else{
                mp["n1s9"]++;
            }
        }else{
            mp["s1"]++;
        }
        if(pots.count(i)){
            cout << i << " " << cnt-last<< ln;
            for(auto [k,v] : mp){
                cout << k << " " << v - lastmp[k] << ln;
                lastmp[k] = v;
            }
            last = cnt;
        }
    }
    return 0;
}