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
vector<vector<p64>> g;
v64 human_time;

void dij(ll s, v64& d, v64& p, ll start){
    ll n = g.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = start;

    priority_queue<p64> pq;
    pq.push({-start,s});
    
    while (!pq.empty()){
        ll u = pq.top().second;
        ll d_u = -pq.top().first;
        pq.pop();


        if(d_u > human_time[u]) continue;
        if(d_u != d[u]) continue;

        for(auto edge : g[u]){
            ll v = edge.first;
            ll w_v = edge.second;
            
            if(d[u] + w_v < d[v]){
                if(d[u] + w_v > human_time[v]) continue;
                
                d[v] = d[u] + w_v;

                p[v] = u;
                pq.push({-d[v], v});
            }
        }
    }
}

int main(){
    _;
    ll n, m, k; cin >> n >> m >> k;
    g.resize(n);
    forn(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        a--;b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    human_time.resize(n, INF);
    priority_queue<p64> pq;
    forn(i, 0, k) {
        ll x; cin >> x;
        x--;
        pq.emplace(-0, x);
    }   


    while (pq.size()) {
        auto p = pq.top();
        pq.pop();
        ll w = -p.first;
        ll u = p.second;
        if (human_time[u] <= w) continue;
        human_time[u] = w;
        
        for(auto [v, vw] : g[u]) {
            vw *= 2;
            if (human_time[u] + vw < human_time[v]) {
                pq.emplace(-(human_time[u] + vw), v);
            }
        }
    }

    v64 d;
    v64 p;

    ll l = 0, r = 2000000000, ans = -1;
    while (l <= r) {
        ll mid = l + (r-l)/ 2;

        dij(0, d, p, -mid);
        debug(mid);
        // for(ll x: d){ cout << x << " ";} cout << ln;
 
        if (d[n-1] != INF) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << ln;
    return 0;
}