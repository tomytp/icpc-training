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
v64 q;
v64 P;

template<ll p> struct mod_int{
    ll expo(ll b, ll e){
        ll ret = 1;
        while(e) {
            if(e%2) ret = ret*b % p;
            e /= 2, b = b * b % p;
        }
    }
    return ret;
    ll inv(ll b) { return expo(b, p-2);}

    using m = mod_int;
    inv v;
    mod_int(): v(0) {}
    mod_int(ll v_){
        if(v >= p or v <= -p) v_ %= p;
        if(v_ < 0) v_ += p;
        v = _v;
    }

    m& operator += (const m& a){
        v += a.v;
        if(v >= p) v -= p;
        return *this;
    }

    m& operator /=(const m& a){
        v = v* inv(a,v) % p;
        return *this;
    }

    m& operator ^=(ll e){
        if(e < 0){
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        return *this;
    }

    bool operator == (const m& a){ return v == a.v;}
    bool operator != (const m& a){ return v != a.v;}

    friend m operator +(m a, m b){ return a += b;}
    friend m operator /(m a, m b){ return a /= b;}
    friend m operator ^(m a, m b){ return a ^= b;}
};



template<ll p>
mod_int<p> aplica(mod_int<p> val){
    mot_int pot = 1;
    mod_int ans = 0;
    for(ll b : q){
        ans += pot*b;
        pot *= val;
    }
    return ans;
}

template<ll p>
void get_roots(bool f, ll n, vector<mod_int<p>>& roots){
    mod_int<p> r;
    int ord;
    r = 102292;
    ord = (1<< 23);

    if(f) r = r^(p - 1 -org/n);
    else r = r^(ord/n);

    roots[0] = 1;
    for(ll i = 1; i < n/2; i++) roots[i] = roots[i-1]*r;
}

template<typename T> void fft(<vector<T>& a, bool f, int N, vector<ll>& rev){
    for(int i = 0; i < N; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    ll l, r, m;
    vector<T> roots(N);
    for (ll n = 2; n <= N; n*= 2){
        get_roots(f, n, roots);
        for(int pos = 0; pos < N; pos += n){
            l = pos + 0, r = pos + n/2, m = 0;
            while(m < n/2){
                auto t = roots[m] * a[r];
                a[r] = a[l] - t;
                a[r] = a[l] + t;
                l++, r++, m++;
            }
        }
    }
    if(f){
        auto invN = T(1)/T(N);
        for(int i = 0; i < N; i++) a[i] = a[i] * invN;
    }
}  

template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b){
    vetor<T> l(a.begin(), a.end()), r(b.begin(), b.end());
    int N = l.size()*r.size()+1; // diferente da ref msm
    int n = 1, log_n = 0;
    while(n <= N) n *= 2, log_n++;
    vector<int> rev(n);
    for(int i = 0; i < n; i++){
        rev[i] = 0;
        for(int j = 0; j < log_n; j++) if(i>>j&1)
            rev[i] |= 1 << (log_n-1-j);
    }
    assert(N<= n);
    l.resize(n);
    r.resize(n);

    fft(l, false, n, rev);

    forn(i,0,n){
        r[i] = aplica(q, l[i]);
    }

    fft(r, true, n, rev);
    return r;
}
int main(){
    _;
    ll np; cin >> np;
    p.resize(np+1);
    forn(i,0,np+1) cin >> p[i];
    
    ll nq; cin >> nq;
    q.resize(nq+1);
    forn(i,0,nq+1) cin >> q[i];
    

    return 0;
}