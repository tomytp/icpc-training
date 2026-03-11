#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _; ll n; cin >> n;
    vector<v64> g(n);
    forn(i, 0, n-1){
        ll a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll root, core;
    forn(i,0,n){
        if(sz(g[i]) == n-1){
            cout << "NO" << ln;
            return 0;
        }
        if(sz(g[i]) == 1){
            root = i;
            core = g[i][0];
        }
    }

    v64 h(n), h_sub(n);
    h[root] = 0;

    function<void (ll, ll)> height = [&](ll curr, ll parent){
        h[curr] = h[parent] + 1;
        h_sub[curr] = h[curr];
        for(auto nxt : g[curr]) if(nxt != parent){
            height(nxt, curr);
            h_sub[curr] = max(h_sub[curr], h_sub[nxt]);
        }
    };

    height(core, root);
    cout << "YES" << ln;

    ll last_height = 0;

    v64 resp;

    bool feito = false;
    function<void (ll, ll)> dfs = [&](ll curr, ll parent){
        if(curr != core) resp.push_back(curr);

        set<p64> s;
        for(auto nxt : g[curr]) if(nxt != parent) s.insert({h_sub[nxt], nxt});

        for(auto [h_nxt, nxt] : s){
            last_height = h_sub[curr];
            dfs(nxt, curr);
            if(!feito && curr == core && h_nxt > 2){
                resp.push_back(curr);
                feito = true;
            }
        }
    };

    
    dfs(core, root);
    resp.push_back(root);

    forn(i,0,n) cout << resp[i]+1 << " \n"[i==n-1];
    debugv(h);

    return 0;
}
