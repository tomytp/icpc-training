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

int main(){
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    v64 soldados(n);
    forn(i, 1, n) cin >> soldados[i];

    forn(i, 0, n-1) {
        ll u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll best_val = 0, best_round = INF;

    function<map<ll,ll> (ll, ll, ll)> dfs = [&](ll u, ll p, ll h) {
        map<ll,ll> mp;
        mp[h] = soldados[u];

        if (soldados[u] > best_val || (soldados[u] == best_val && best_round > 0)) {
            best_round = 0;
            best_val = soldados[u];
        } 

        for (auto v : g[u]) {
            if (v == p) continue;
            
            auto temp = dfs(v, u, h+1);
            if (mp.size() < temp.size()) swap(temp, mp);
            for (auto [key, val] : temp) {
                mp[key] += val;
                if (u != 0 && (mp[key] > best_val || (mp[key] == best_val && best_round > key - h))) {
                    best_round = key - h;
                    best_val = mp[key];
                }
            }
        }

        // debug(u+1);
        // for(auto& p: mp) cout << p.first << " : " << p.second << " ";; cout << ln;
        return mp;
    };

    dfs(0, -1, 0);

    cout << best_val << " " << best_round + 1 << ln;
    return 0;
}
