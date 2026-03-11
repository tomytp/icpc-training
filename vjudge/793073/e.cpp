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
    _;
    ll n, m; cin >> n >> m;
    vector<v64> g(n);
    vector<p64> edgs;
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edgs.emplace_back(a, b);
    }

    ll gbest = INF;
    ll gans = 0;

    function<void (ll)> solve = [&](ll root) {
        ll best = INF;

        queue<ll> q;
        v64 p(n, -1), h(n, -1), f(n, 0);
        q.push(root);
        p[root] = root;
        h[root] = 0;

        while (sz(q)) {
            ll u = q.front();
            q.pop();

            for (auto v : g[u]) {
                if (v == p[u]) continue;
                if (h[v] == -1) {
                    q.push(v);
                    f[v]++;
                    h[v] = h[u] + 1;
                    p[v] = u;
                } else {
                    ll len = h[u] + h[v] + 1;
                    if (h[v] > h[u]) f[v]++;
                    best = min(best, len);
                }
            }
        }

        if (best > gbest) return;
        if (best < gbest) {
            gbest = best;
            gans = 0;
        }

        if (best % 2 == 0) {
            forn(i, 0, n) {
                if (h[i] == best/2) {
                    gans += (f[i] * (f[i]-1))/2;
                }
            }
        } else {
            for (auto [a, b] : edgs) {
                if (h[a] == best/2 && h[b] == h[a]) {
                    gans += (f[a] * f[b]);
                }
            }
        }
        debug(gbest);
        debugv(f);
        debugv(h);
    };


    forn(i, 0, n) {
        solve(i);
    }

    cout << gans / gbest << ln;
    return 0;
}
