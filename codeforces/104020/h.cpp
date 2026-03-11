#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
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
    vector<vector<p64>> g(n);
    map<p64,ll> traduz;
    v64 resp(n);
    forn(i, 0, n){
        ll a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});

        traduz[p64(a,b)] = i;
        traduz[p64(b,a)] = i;
    }
    vector<bool> cycle(n,false);
    v64 up(n), down(n), c_up(n), c_down(n);
    vector<set<ll>> color(n);

    vector<bool> vis(n, false);

    function<void (ll, ll, ll&, bool&)> find_cycle = [&](ll curr, ll prev, ll&found, bool& fim){
        if(vis[curr]){
            found = curr;
            return;
        }
        vis[curr] = true;
        for(auto [nxt, c_nxt] : g[curr]){
            if(nxt == prev) continue;
            find_cycle(nxt, curr, found, fim);
            if(fim) return;
            if(found != -1){
                up[nxt] = curr;

                down[curr] = nxt;

                c_up[nxt] = c_nxt;
                c_down[curr] = c_nxt;
                break; 
            }
        }
        
        if(found != -1) cycle[curr] = true;
        if(found == curr) fim = true;
    };

    ll found = -1;
    bool fim = false;
    find_cycle(0, -1, found, fim);

    debugv(cycle);
    debugv(up);
    debugv(down);

    bool deu_ruim = false;
    function<void (ll, ll)> coloring = [&](ll curr, ll prev){
        for(auto [nxt, c_nxt] : g[curr]){
            if(nxt == prev) continue;
            if(cycle[nxt]) continue;

            color[nxt].insert(1);
            if(color[curr].count(c_nxt)) deu_ruim = true;
            color[curr].insert(c_nxt);

            resp[traduz[p64(curr, nxt)]] = nxt;

            coloring(nxt, curr);
        }
    };

    forn(i, 0, n) if(cycle[i]) coloring(i, -1);

    if(deu_ruim){
        cout << "impossible" << ln;
        return 0;
    }

    ll ini = 0;
    while(!cycle[ini]) ini++;

    deu_ruim = false; 
    ll curr = ini; 

    do{
        ll nxt = up[curr], c_nxt = c_up[curr];
        if(color[curr].count(c_nxt)) deu_ruim = true;
        debug(curr);
        debug(nxt);
        resp[traduz[p64(curr, nxt)]] = nxt;
        curr = nxt;
    } while(curr != ini);

    if(!deu_ruim){
        forn(i, 0, n) cout << resp[i] + 1 << " ";
        cout << ln;
        return 0;
    }

    deu_ruim = false;
    curr = ini;

    do{
        ll nxt = down[curr], c_nxt = c_down[curr];
        if(color[curr].count(c_nxt)) deu_ruim = true;
        resp[traduz[p64(curr, nxt)]] = nxt;
        curr = nxt;
    } while(curr != ini);

    if(deu_ruim){
        cout << "impossible" << ln;
        return 0;
    }

    forn(i, 0, n) cout << resp[i] + 1 << " ";
    cout << ln;

    return 0;
}