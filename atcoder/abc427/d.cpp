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
    ll n, m, k; cin >> n >> m >> k;
    string s; cin >> s;

    vector<v64> g(n);
    forn(i, 0, m) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    v64 dpa_last(n), dpb_last(n);
    forn(u, 0, n) {
        ll a_best = (s[u] == 'A');
        dpa_last[u] = a_best;
        dpb_last[u] = a_best;
    }

    ll supr = 2 * k;
    forn (r, 1, supr + 1) {
        v64 dpa(n), dpb(n);

        forn(u, 0, n) {
            ll res = 0;
            for (int v : g[u]) {
                if (dpb_last[v]) { 
                    res = 1;
                    break; 
                }
            }
            dpa[u] = res;
        }

        forn(u, 0, n) {
            ll res = 1;
            for (int v : g[u]) {
                if (!dpa_last[v]) {
                    res = 0; break; 
                }
            }
            dpb[u] = res;
        }

        dpa_last.swap(dpa);
        dpb_last.swap(dpb);
    }

    if (dpa_last[0]) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}