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

int main(){
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    function<void (ll, ll, v64&)> dfs = [&](ll u, ll p, v64& dist) {
        dist[u] = dist[p] + 1;

        for (auto v : g[u]) {
            if (v == p) continue;

            dfs(v, u, dist);
        }
    };
    v64 dist0(n);
    dfs(0, 0, dist0);

    ll a = 0;
    forn(i, 0, n) {
        if (dist0[a] <= dist0[i]) a = i;
    }

    v64 dista(n);
    dfs(a, a, dista);

    ll b = 0;
    forn(i, 0, n) {
        if (dista[b] <= dista[i]) b = i;
    }

    v64 distb(n);
    dfs(b, b, distb);

    if (a < b) {
        swap(a, b);
        swap(dista, distb);
    } 

    forn(i, 0, n) {
        if (dista[i] >= distb[i]) {
            cout << a+1 << ln;
        } else {
            cout << b+1 << ln;
        }
    }
    return 0;
} 