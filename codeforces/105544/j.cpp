#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(ll n) {
    ll m; cin >> m;
    v64 cost(n);   
    cin >> cost[0];
    forn(i,1,n) {
        char lixo;
        cin >> lixo >> cost[i];
    }
    vector<vector<p64>> g(n);
    forn(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }

    v64 from(n), count(n), dp(n);
    from[0] = -1;
    forn(i, 0, n) {
        dp[i] += cost[i];
        for (auto v: g[i]) {
            ll my_cost = dp[i] + v.second;
            if (my_cost > dp[v.first]) {
                dp[v.first] = my_cost;
                from[v.first] = i;
                count[v.first] = 1;
            } else if (my_cost == dp[v.first]) {
                count[v.first]++;
            }
        }
    }

    v64 path = {};
    ll curr = n-1;
    while (curr != -1) {
        if (count[curr] > 1) {
            path.clear();
            break;
        }
        path.push_back(curr);
        curr = from[curr];
    }
    if (!path.size()) {
        cout << dp[n-1] << ",M\n";
        return;
    }
    cout << dp[n-1];
    reverse(path.begin(), path.end());
    forn(i, 0, path.size()) cout << "," << path[i];
    cout << ln;
}

int main() {
    _;
    ll n; 
    while (cin >> n) {
        solve(n);
    }
    return 0;
}