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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1'000'000'007;

#define MODULAR true
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
            e >>= 1ll;
            at = at*at;
        }
        return M;
    }
    void apply_transform(matrix M, ll e){
        auto& v = *this;
        while (e) {
            if(e&1) v = M*v;
            e >>= 1ll;
            M = M*M;
        }
    }
};

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

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 401;

ll n;
ll d[MAX][MAX], d1[MAX][MAX];

struct query {
    ll a, b, idx;
};

vector<vector<query>> quente, fria;
v64 ans;


void print() {
    forn(i, 0, n) {
        forn(j, 0, n) {
            cout << d[i][j] << "\t\n"[j == n-1];
        }
    }
}

void floyd_warshall(vector<p64>& order, vector<vector<query>>& qr, ll mat[MAX][MAX]) {
    ll ord = 0;
    ll prev_t = -1;
    v64 qx;
    for(auto [temp, k] : order) {
        if (prev_t != -1 && temp != prev_t) {
            for (auto x : qx) {
                for (auto q : qr[x]) {
                    ans[q.idx] = mat[q.a][q.b];
                }
            }
            qx.clear();
        }

        forn(i, 0, n) {
            forn(j, 0, n) mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
        // print();

        qx.push_back(ord);
        ord++;
        prev_t = temp;
    }
    for (auto x : qx) {
        for (auto q : qr[x]) {
            ans[q.idx] = mat[q.a][q.b];
        }
    }
}



int main() {
    _;
    ll r; cin >> n >> r;
    v64 temp(n);
    forn(i, 0, n) {
        forn(j, 0, n) d[i][j] = INF, d1[i][j] = INF;
    }

    forn(i, 0, n) cin >> temp[i];
    forn(i, 0, r) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        d1[a][b] = c;
        d1[b][a] = c;
    }




    ll q; cin >> q;
    ans.resize(q);
    quente.resize(n);
    fria.resize(n);
    forn(i, 0, q) {
        ll a, b, k, t; cin >> a >> b >> k >> t;
        a--; b--; k--;
        if (t == 0) {
            fria[k].push_back({a, b, i});
        } else {
            quente[k].push_back({a, b, i});
        }
    }

    vector<p64> order(n);
    forn(i, 0, n) {
        order[i] = {temp[i], i};
    }
    sort(order.begin(), order.end());
    floyd_warshall(order, fria, d);
    sort(order.rbegin(), order.rend());
    floyd_warshall(order, quente, d1);
    
    forn(i, 0, q) cout << (ans[i] != INF ? ans[i] : -1) << ln;
        
    return 0;
}
ll pot(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp & 1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp >>= 1;
    }        
    return res;
}

int main() {
    _;
    ll n; cin >> n;
    if(n==1){
        cout << 2 << ln;
        return 0;
    }
    matrix<ll> mat(3,3);

    mat[0][1] = 1;
    mat[1][2] = 1;
    mat[2][0] = MOD-1;
    mat[2][2] = 2;

    matrix<ll> v(3,1);
    v[0][0] = MOD-1;
    v[1][0] = MOD-1;
    v[2][0] = 0;

    mat = mat^n;

    auto vec_s = mat*v;
    
    // mat.print();
    // vec_s.print();
    
    ll pot2 = pot(2,n);
    // cout << pot2 << ln;

    ll next_pot2 = 2*pot2;
    if(next_pot2 >= MOD) next_pot2 -= MOD;

    ll s = vec_s[0][0], f = (MOD+vec_s[2][0]-vec_s[1][0])%MOD;

    ll resp1 = (next_pot2 * s)%MOD;
    ll resp2 = (next_pot2 * f)%MOD;
    ll resp3 = (pot2 * (n-1))%MOD;
    resp1 = (resp1 + resp2)%MOD;
    resp1 = (resp1 - resp3 + MOD)%MOD;

    cout << (resp1*2)%MOD << ln;
    return 0;
}