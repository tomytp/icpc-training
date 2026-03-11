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

const ll N = 1'000'000;
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

struct mod_int {
    ll p;

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
    mod_int(ll v_, ll p_) {
        p = p_;
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
    m operator -() const { return m(-v,p); }
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

    friend ostream& operator <<(ostream& out, m a) {
        return out << a.v;
    }
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll e) { return a ^= e; }
};

ll tenta(ll p, ll k, v64& s){
    mod_int dem(s[1]-s[0], p);
    mod_int numa(s[2] - s[1], p);
    mod_int numb(s[1]*s[1] - s[2]*s[0], p);

    mod_int a = numa/dem;
    mod_int b = numb/dem;

    mod_int seq(s[0], p); 
    forn(i,1,k){
        seq = a*seq + b;
        if(seq.v != s[i]) return -1;
    }
    seq = a*seq + b;

    return seq.v;
}

void solve(){
    ll k, d; cin >> d >> k;
    v64 s(k);
    forn(i, 0, k) cin >> s[i];
    
    if(k == 1){
        cout << "I don't know." << ln;
        return;
    }

    if(s[0] == s[1]){
        cout << s[0] << ln;
        return;
    }

    if(k == 2){
        cout << "I don't know." << ln;
        return;
    }

    ll resp = -1;
    ll pot = 1;
    forn(i,0,d) pot*=10;   

    for(auto p : pr){
        if(p >= pot) break;    
        if(p <= s[0]) continue;
        ll guess = tenta(p, k, s);
        if(guess == -1) continue;
        if(resp == -1){
            resp = guess; 
            continue; 
        }
        if(resp == guess) continue;

        cout << "I don't know." << ln;
        return;
    }
    assert(resp != -1);
    cout << resp << ln;
}

int main(){
    _; sieve();
    ll t;
    cin >> t;
    forn(i, 0, t){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}