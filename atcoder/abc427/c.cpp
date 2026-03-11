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
    vector<p64> edges(m);
    forn(i, 0, m) cin >> edges[i].first >> edges[i].second;
    forn(i, 0, m) edges[i].first--, edges[i].second--;

    bitset<10> bt;
    ll ans = INF;

    function<ll (bitset<10>)> solve = [&](bitset<10> curr) {
        ll x = 0;
        forn(i, 0, m) {
            if (bt[edges[i].first] == bt[edges[i].second]) x++;
        }
        return x;
    };

    function<void (ll)> run = [&](ll idx) {
        if (idx == n) {
            ans = min(ans, solve(bt));
            return;
        }

        run(idx+1);
        bt[idx] = true;
        run(idx+1);
        bt[idx] = false;
    };
    run(0);
    cout << ans << ln;
    
    return 0;
}