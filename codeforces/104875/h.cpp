#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b); 
        g[b].push_back(a);
    }

    v64 mx(n, INF), hh(n);
    function<ll (ll, ll, ll)> dfs = [&](ll u, ll p, ll h) {
        ll a = -1, b = -1;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (a == -1) a = v;
            else b = v;
        }

        if (a == -1) {
            mx[u] = h;
            return h;
        }

        if (b == -1) {
            mx[u] = h+1;
            return h+1;
        }
        
        ll h1 = dfs(a, u, h+1);
        ll h2 = dfs(b, u, h+1);
        
        if (h1 == h2) {
            mx[u] = h1;
            return h1;
        }

        mx[u] = min(h1, h2) + 1; 
        return min(h1, h2) + 1;
    }; 
    dfs(0, -1, 0);
    
    vector<bool> bad(n);
    function<void (ll, ll, ll, ll)> dfs2 = [&](ll u, ll p, ll mh, ll h) {
        if (h > mh) bad[u] = true;
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs2(v, u, min(mh, mx[u]), h+1);
        }
    }; 

    dfs2(0, -1, INF, 0);
    ll ans = 0;
    forn(i, 0, n) if (bad[i]) ans++;   
    cout << ans << ln;
    
    return 0;
}