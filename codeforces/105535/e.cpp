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

vector<ll> ans;

void dfs(ll u, ll parent, vector<v64>& g, v64& pesos) {
    pesos[u]--;
    ans.push_back(u);

    for(auto v : g[u]) {
        if (v == parent) continue;
        while(pesos[v] > 0) {
            dfs(v, u, g, pesos);
            ans.push_back(u);
            pesos[u]--;
        }
    }

    if (pesos[u] < 0) {
        cout << 0 << ln;
        exit(0);
    }
}

int main(){
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    v64 pesos(n);
    forn(i, 0, n) cin >> pesos[i];
    pesos[0]++;
    forn(i,0, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1, g, pesos);

    if (pesos[0] != 0) {
        cout << 0 << ln;
        return 0;
    }

    forn(i, 0, ans.size()) {
        cout << ans[i]+1 << " \n"[i==ans.size() - 1];
    }


    return 0;
}