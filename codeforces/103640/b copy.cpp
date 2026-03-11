#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double ep = 0.0001;
using cd = complex<double>;

ll convert(cd c){
    double r = c.real();
    if(r < ep && r > -ep) return 0;
    if(r > ep){
        return (ll)(r + 0.5);
    }
    r = -r;
    return (-1)*(ll)(r + 0.5);
}

void get_roots(bool f, int n, vector<complex<double>>& roots) {
    const static double PI = acosl(-1);
    for (int i = 0; i < n/2; i++) {
        double alpha = i*((2*PI)/n);
        if (f) alpha = -alpha;
        roots[i] = {cos(alpha), sin(alpha)};
    }
}

template<typename T> void fft(vector<T> & a, bool f, int N, vector<int>& rev) {
    for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    ll l, r, m;
    vector<T> roots(N);
    for (int n = 2; n <= N; n*= 2) {
        get_roots(f, n, roots);
        for (int pos = 0; pos < N; pos += n) {
            l = pos + 0, r = pos + n/2, m = 0;
            while (m < n/2) {
                auto t = roots[m] * a[r];
                a[r] = a[l] - t;
                a[l] = a[l] + t;
                l++, r++, m++;
            }
        }
    }

    if (f) {
        auto invN = T(1) / T(N);
        for (int i = 0; i < N; i++) a[i] = a[i] * invN;
    }
}

template<typename T> vector<T> convolution(vector<T> & a, vector<T>& b) {
    vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
    int N = l.size() + r.size() - 1;
    int n = 1, log_n = 0;
    while (n <= N) n *= 2, log_n++;
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = 0;
        for (int j = 0; j < log_n; j++) if (i>>j&1)
            rev[i] |= 1 << (log_n-1-j);
    }
    assert(N<=n);
    l.resize(n);
    r.resize(n);
    fft(l, false, n, rev);
    fft(r, false, n ,rev);

    for (int i = 0; i < n; i++) l[i] *= r[i];
    fft(l, true, n, rev);
    l.resize(N);
    return l;
} 

v64 solve(v64 a, v64 b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll n = a.size();
    ll st = 0, nd = n-1;

    v64 resp;
    resp.push_back(0);
    
    //TODO CHECAR BORDAS
    while (st <= nd && (a[st] * b[st] >= 0 || a[nd] * b[nd] >= 0)) {
        ll best = -1;
        bool choose_st = false;
        if(a[st]*b[st]>= 0){
            if(a[st]*b[st] >= best){
                best = a[st]*b[st];
                choose_st = true;
            }
        }
        if(a[nd]*b[nd]>= 0){
            if(a[nd]*b[nd] >= best){
                best = a[nd]*b[nd];
                choose_st = false;
            }
        }

        resp.push_back(resp.back()+best);
        if(choose_st) st++;
        else nd--;
    }

    // for(ll x: resp) cout << x << " ";; cout << ln;
    if(resp.size() == n+1) return resp; 

    vector<cd> a_cut, b_cut;
    forn(i, st, nd+1){
        a_cut.push_back({(double)a[i], (double)0});
        b_cut.push_back({(double)b[i], (double)0});
    }
    
    reverse(b_cut.begin(), b_cut.end());

    ll last = resp.back();
    vector<cd> fefete = convolution<cd>(a_cut, b_cut);
    reverse(fefete.begin(), fefete.end());
    
    // for(auto x : fefete) cout << x << " ";; cout << ln;
    // for(auto x : fefete) cout << convert(x) << " ";; cout << ln;
    

    ll aux = a_cut.size();
    forn(i, 0, aux){
        resp.push_back(last + convert(fefete[i]));
    }

    return resp;
}

int main() {
    _;
    ll n; cin >> n;
    v64 a(n), b(n), b_neg(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i], b_neg[i] = -b[i];

    v64 r1 = solve(a, b);
    v64 r2 = solve(a, b_neg);

    // for(auto x : r1) cout << x << " ";; cout << ln;
    // for(auto x : r1) cout << x << " ";; cout << ln;

    forn(i, 1, n+1){
        cout << -r2[i] << " " << r1[i] << ln;
    }
    
    return 0;
}