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
    _;
    ll n, i, t; cin >> n >> i >> t;
    vector<v64> dp(n+1, v64(n+1));
    vector<p64> ir(1), tr(1);
    ir.reserve(n);
    tr.reserve(n);

    forn(j, 0, n) {
        ll il, ih, tl, th; cin >> il >> ih >> tl >> th;
        trace(cout << il << " " << tl << " " << ih << " " << th << ln;);
        il -= i;
        ih -= i;
        tl -= t;
        th -= t;
        trace(cout << il << " " << tl << " " << ih << " " << th << ln;);
        if (il < 0 || tl <0 || ih > n || th > n) continue;

        ir.emplace_back(il, ih);
        tr.emplace_back(tl, th);
    }

    n = sz(ir)-1;
    
    auto test = [&](ll implementation, ll prob, p64 ir, p64 tr){
        ll thinking = prob - implementation;
        if(implementation < ir.first) return false;
        if(implementation > ir.second) return false;
        if(thinking < tr.first) return false;
        if(thinking > tr.second) return false;
        return true;
    };

    // dp[prob][impl] = num resolvidos considerando o problema prob
    // indexado a 1 no prob

    forn(prob, 1, n+1){
        dp[prob][0] = dp[prob-1][0];
        if(test(0, dp[prob][0], ir[prob], tr[prob])){
            dp[prob][0]++;
        }
    }

    forn(prob, 1, n+1) {
        forn(impl, 1, n+1) {
            // nao resolvo esse
            dp[prob][impl] = dp[prob-1][impl];

            // resolvo esse e upo impl
            if(test(impl-1, dp[prob-1][impl-1], ir[prob], tr[prob])){
                dp[prob][impl] = max(dp[prob][impl], dp[prob-1][impl-1] + 1);
            }

            // resolvo esse e upo thin
            if(test(impl, dp[prob-1][impl], ir[prob], tr[prob])){
                dp[prob][impl] = max(dp[prob][impl], dp[prob-1][impl] + 1);
            }
        }
    }
    
    ll resp = 0;
    forn(j,0,n+1) resp = max(dp[n][j], resp);

    cout << resp << ln;
    return 0;
}
