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

void solve() {
    ll n; cin >> n;
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    v64 deg(n), h(n);

    function<void (ll, ll)> dfs1 = [&](ll u, ll p) {
        if (u != n-1) h[u] = h[p] + 1;

        for (auto v : g[u]) {
            if (v == p) continue;
            deg[u]++;
            dfs1(v, u);
        }
    };
    dfs1(n-1, -1);

    vector<p64> par, impar;
    forn (i, 0, n) {
        if (h[i] % 2 == 0) {
            par.push_back({h[i], i});
        } else {
            impar.push_back({h[i], i});
        }
    }
    sort(par.rbegin(), par.rend());
    sort(impar.rbegin(), impar.rend());

    bool cat_par = (h[0] %2 == 0);
    vector<p64> ops;
    ll alive = n;
    ll ip = 0, ii = 0;
    while (alive > 1) {
        ll ispar = par[ip].first > impar[ii].first;
        alive--;
        if (ispar) {
            if (cat_par) {
                ops.push_back({1, 0});
                ops.push_back({2, par[ip].second + 1});
                ops.push_back({1, 0});
                ip++;
            } else {
                ops.push_back({2, par[ip].second + 1});
                ops.push_back({1, 0});
                cat_par = !cat_par;
                ip++;
            }
        } else {
            if (cat_par) {
                ops.push_back({2, impar[ii].second + 1});
                ops.push_back({1, 0});
                cat_par = !cat_par;
                ii++;
            } else {
                ops.push_back({1, 0});
                ops.push_back({2, impar[ii].second + 1});
                ops.push_back({1, 0});
                ii++;
            }
        }
    }

    cout << sz(ops) << ln;
    forn(i, 0, sz(ops)) {
        if (ops[i].first== 1) {
            cout << 1 << ln;
        }  else {
            cout << 2 << " " << ops[i].second << ln;
        }
    }
    cout << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
} 