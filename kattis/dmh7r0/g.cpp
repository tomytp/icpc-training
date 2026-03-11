#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld DINF = 1e18;
const ld eps = 1e-10;

ll cmp(ld x, ld y, ld tol = eps){
    return (x <= y + tol) ? (x+tol<y) ? -1 : 0 : 1;
}

int main() {
    _; ll r, c, t; cin >> r >> c >> t;
    vector<vector<double>> dp(r, vector<double>(c,0));

    for(ll i = r-1; i>=0; i--)
    for(ll j = c-1; j>=0; j--){
        if(i == r-1 && j == c-1) continue;
        ld a = DINF;
        ld b = DINF;
        if(i+1 < r) a = dp[i+1][j];
        if(j+1 < c) b = dp[i][j+1];

        if(cmp(a,b) > 0) swap(a,b);

        ld delta = b-a;
        if(cmp(delta, t) >= 0) delta = t;

        dp[i][j] = a/2 + ((delta*a) + delta*delta/2 + (t-delta)*b)/(2*t);
    }

    cout << fixed << setprecision(20) << dp[0][0] << ln;
    return 0;
}