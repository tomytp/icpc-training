#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld MAX = 14001;

int main() {
    _; ll h, w; cin >> h >> w;
    vector<string> tower(h);
    forn(i, 0, h){
        cin >> tower[i];
    }

    ld r = 5;
    ld pi = acos(0)*5;

    vector<vector<ld>> dp(2*h+1, vector<ld>(2*w+1, MAX));
    dp[0][0] = 0;
    forn(i, 1, 2*h+1) dp[i][0] = dp[i-1][0] + r;
    forn(j, 1, 2*w+1) dp[0][j] = dp[0][j-1] + r;

    forn(i, 1, 2*h+1){
        forn(j, 1, 2*w+1){
            if(i%2 == 1 && j%2 == 1) continue;
            if(i%2 == 0 && j%2 == 0){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + r;
                continue;
            }
            ll convert_i, convert_j;
            if(i%2 == 1) {
                dp[i][j] = dp[i-1][j] + r;
                convert_i = (i-1)/2;
                convert_j = (j-2)/2;
            }
            if(j%2 == 1){
                dp[i][j] = dp[i][j-1] + r;
                convert_i = (i-2)/2;
                convert_j = (j-1)/2;
            }

            if(tower[convert_i][convert_j] == 'O'){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+pi);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[2*h][2*w] << ln;
    return 0;
}