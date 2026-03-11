#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll MOD = 1'000'000'007;

#define MODULAR false
template<typename T> struct matrix : vector<vector<T>> {
    ll n, m;
    void print() {
        forn(i,0,n) {
            forn(j,0,m) cout << (*this)[i][j] << " ";
            cout << endl;
        }
    }

    matrix(ll n_, ll m_, bool ident = false) :
            vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
        if(ident) {
            assert(n == m);
            forn(i,0,n) (*this)[i][i] = 1;
        }           
    }
    matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
        n(c.size()), m(c[0].size()) {}
    
    matrix<T> operator*(matrix<T>& r){
        assert(m == r.n);
        matrix<T> M(n,r.m);
        forn(i,0,n) forn(k,0,m) forn(j,0,r.m){
            T add = (*this)[i][k] * r[k][j];
#if MODULAR
            M[i][j] += add%MOD;
            if(M[i][j] >= MOD) M[i][j] -= MOD;
#else
            M[i][j] += add;
#endif
        }
        return M;
    }
    matrix<T> operator^(ll e){
        matrix<T> M(n, n, true), at = *this;
        while(e) {
            if(e&1) M = M*at;
            e >>= 1;
            at = at*at;
        }
        return M;
    }
    void apply_transform(matrix M, ll e){
        auto& v = *this;
        while (e) {
            if(e&1) v = M*v;
            e >>= 1;
            M = M*M;
        }
    }
};