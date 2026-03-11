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
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string s; cin >> s;
    
    queue<tuple<ll,ll,ll>> q;
    ll missing = 0;
    vector<p64> b1(n, {INF, -1}), b2(n, {INF, -1});
    forn(i, 0, n) {
        if (s[i] == 'S') {
            q.emplace(i, 0, i);
            b1[i] = {0, i};
        } else {
            missing++;
        }
    }


    while (q.size() && missing) {
        auto [u, dist, src] = q.front(); q.pop();
        for (ll v : g[u]) {
            ll nd = dist + 1;
            if (src != b1[v].second && nd < b1[v].first) {
                if (b1[v].second != -1 && b1[v].second != src) {
                    if (b2[v].first > b1[v].first) b2[v] = b1[v];
                }
                b1[v] = {nd, src};
                q.emplace(v, nd, src);
            }
            else if (src != b1[v].second && src != b2[v].second && nd < b2[v].first) {
                b2[v] = {nd, src};
                q.emplace(v, nd, src);
            }
            if (s[v]=='D' && b2[v].second != -1) {
            }
        }
    }

    forn (i, 0, n) {
        if (s[i]=='D') cout << b1[i].first + b2[i].first << ln;
    }


    return 0;
}