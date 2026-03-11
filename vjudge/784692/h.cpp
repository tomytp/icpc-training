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

void solve(){
    ll l, n; cin >> l >> n;
    v64 steps(n);
    ll m = 0, d = 0;
    forn(i, 0, n){
        cin >> steps[i];
        m = max(m, steps[i]);
        d = gcd(d,steps[i]);
    } 

    debug(d);
    debug(m);

    if(l%d != 0){
        cout << "IMPOSSIBLE" << ln;
        return;
    }

    vector<pair<ll,ll>> dp(m, {-1,-1});
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,0});
    dp[0] = {0,0};

    auto get_prio = [&](p64 p){
        if(p.first == -1) return -INF;
        return (p.first/m - p.second);
    };

    while(!pq.empty()){
        auto [prio, curr] = pq.top();
        pair<ll,ll> p = dp[curr];
        pq.pop();

        if(get_prio(dp[curr]) != prio) continue;

        forn(i, 0, n){
            ll nxt = (curr + steps[i])%m;

            // debug(curr);
            // debug(nxt);
            // debug(steps[i]);
            // trace(ll aux = 0;
            // ll c; cin >> c;
            // aux +=c;);
            
            p64 guess = {p.first+steps[i], p.second+1};
            ll guess_prio = get_prio(guess);
            ll dp_prio = get_prio(dp[nxt]);

            if(dp_prio < guess_prio){
                dp[nxt] = guess;
                pq.push({guess_prio, nxt});
            }
        }
    } 

    trace(
        forn(i,0, m) cout << setw(2) << i << " ";; cout << ln;
        forn(i,0, m) cout << setw(2) << dp[i].first << " ";; cout << ln;
        forn(i,0, m) cout << setw(2) << dp[i].second << " ";; cout << ln;
    );
    auto s = dp[l%m]; 

    cout << s.second + (l-s.first)/m << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t){
        cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}