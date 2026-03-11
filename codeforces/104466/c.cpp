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

vector<vector<p64>> g;

void dijkstra(ll s, v64 &d){
    ll n = g.size();
    d.assign(n, INF);

    d[s] = 0;

    priority_queue<p64> pq;

    pq.push({0,s});

    while(!pq.empty()){
        ll u = pq.top().second;
        ll d_u = - pq.top().first;
        pq.pop();
        if(d_u != d[u]) continue;
        
        for(auto edge: g[u]){
            ll v = edge.first;
            ll w_v = edge.second;

            if(d[u] + w_v < d[v]){
                d[v] = d[u] + w_v;
                pq.push({-d[v],v});
            }
        }
    }
}

int main(){
    _;
    ll n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    v64 tele(k);

    forn(i,0,k){
        cin >> tele[i];
        tele[i]--;
    }

    forn(i,0,m){
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back({b,1});
        g[b].push_back({a,1});
    }

    v64 dini, dfim;

    dijkstra(0, dini);
    dijkstra(n-1, dfim);

    ll best = (k-1)*dini[n-1];

    ll sum_tele = 0;

    forn(i,0,k){
        sum_tele += dfim[tele[i]];
    }

    forn(i,0,k){
        ll curr = (k-1)*dini[tele[i]];
        curr += sum_tele - dfim[tele[i]];
        best = min(curr, best);
    }

    ll num = best;
    ll dem = k-1;
    ll d = gcd(num, dem);
    num /= d;
    dem /= d;

    cout << num << "/" << dem << ln;
    return 0;
}


// test1
// 93: best_tele = 1
// 94: pos2 = 5
// 95: num = 8
// 96: dem = 3
// 8/3

// test2
// 2/1