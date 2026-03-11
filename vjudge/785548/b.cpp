#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

// const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 1'000'000;

struct aho {
    map<char, ll> to[MAX];
    ll link[MAX], idx, exit[MAX], sobe[MAX];
    v64 term;

    vector<v64> g;

    aho(ll n){
        // term.resize(MAX, -1);
        // g.resize(n);
    }

    void insert(string& s, ll i) {
        ll at = 0;
        for (char c : s) {
            auto it = to[at].find(c);
            if (it == to[at].end()) at = to[at][c] = ++idx;
            else at = it->second;
        }
        term[at] = i, sobe[at]++;
    }

    void build() {
        queue<ll> q;
        q.push(0);
        link[0] = exit[0] = -1;
        while (q.size()) {
            ll i = q.front(); q.pop();
            for (auto [c, j] : to[i]) {
                ll l = link[i];
                while (l != -1 and !to[l].count(c)) l = link[l];
                link[j] = l == -1 ? 0 : to[l][c];
                exit[j] = (term[link[j]] == -1) ? term[link[j]] : exit[link[j]];

                if (exit[j]+1) sobe[j] += sobe[exit[j]];
                q.push(j);
            }
        }
    }
    void query(string& s, ll i) {
        ll at = 0;
        for (char c : s){
            while (at != -1 and !to[at].count(c)) at = link[at];
            at = at == -1 ? 0 : to[at][c];
            g[i].push_back(term[at]);
        }
    }
};

v64 topo_sort(const vector<v64>& g) {
    v64 indeg(g.size()), q;
    for (auto& li : g) for (int x : li) indeg[x]++;
    forn(i, 0, g.size()) if (indeg[i] == 0) q.push_back(i);
    forn(j, 0, q.size()) for(int x : g[q[j]]) if(--indeg[x] == 0) q.push_back(x);
    return q;
}

void solve(ll n){
    debug(n);
    aho cora(n);
    // vector<string> dic;
    // forn(i, 0, n){
    //     string s; cin >> s;
    //     dic.push_back(s);
    //     cora.insert(s, i);
    // }

    // cora.build();

    // forn(i, 0, n) cora.query(dic[i], i);

    // auto order = topo_sort(cora.g);
    // v64 dp(n, 0);
    // ll best_best = 0;
    // for(auto curr : order){
    //     ll best = 0;
    //     for(auto nxt : cora.g[curr]) best = max(best, dp[nxt]);
    //     dp[curr] = best+1;
    //     best_best = max(dp[curr], best_best);
    // }

    // cout << best_best << ln;
}
 
int main() {
    _; 
    while(true){
        ll n; cin >> n;
        debug(n);
        if(n == 0) break;
        solve(n);
    }
    return 0;
}
