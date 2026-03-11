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
const ll mx = 1'000'000'000'000'000ll;

void solve() {
    ll n, k; cin >> n >> k;

    v64 pos(n + 2);
    v64 delay(n + 2, 0);

    forn(i, 1, n+1) cin >> pos[i];
    forn(i, 1, n+1) cin >> delay[i];

    pos[0] = 0;
    pos[n + 1] = mx + 1;

    vector<vector<v64>> dp(n + 2, vector<v64>(2, v64(k, -1)));
    vector<vector<v64>> vis(n + 2, vector<v64>(2, v64(k, 0)));

    function<bool(ll,ll,ll)> dfs = [&](ll idx, ll dir, ll t) -> bool {
        auto res = dp[idx][dir][t];
        if (res != -1) return res;
        if (vis[idx][dir][t]) return (dp[idx][dir][t] = 0);
        vis[idx][dir][t] = 1;

        ll num_dir = dir ? 1 : -1;
        ll nx_num_dir = (t == delay[idx]) ? -num_dir : num_dir;
        ll nx_dir = nx_num_dir == 1 ? 1 : 0;
        ll nx_idx = idx + nx_num_dir;
        ll dist = abs(pos[nx_idx] - pos[idx]);
        ll nx_time = (t + dist % k) % k;

        bool ok = (nx_idx == 0 || nx_idx == n + 1) ? true: dfs(nx_idx, nx_dir, nx_time);
        vis[idx][dir][t] = 0;
        return (dp[idx][dir][t] = ok);
    };

    ll q; cin >> q;
    forn(kkk, 0, q) {
        ll a; cin >> a;

        auto it = lower_bound(pos.begin() + 1, pos.begin() + n + 1, a);
        bool ans;

        if (it != pos.begin() + n + 1 && *it == a) { // cravou num sinal
            ll idx = it - pos.begin();
            ans = dfs(idx, 1, 0);
        } else {
            ll r_idx = it - pos.begin();
            if (r_idx == n + 1) { // ja comeca fora
                ans = true;
            } else { // pega o proximo sinal a direita
                ll dist = pos[r_idx] - a;
                ll t0 = dist % k;
                ans = dfs(r_idx, 1, t0);
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
