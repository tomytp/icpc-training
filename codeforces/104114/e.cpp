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
#define debugp(v) trace({cout << #v": "; for (auto x : v) cout<< x.first << " " << x.second << " | "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll paire(p64 a, p64 b) {
    if (a.second == b.second) return INF;
    return abs(a.first - b.first);
}

ll testa(vector<p64>& vec){
    ll resp = 0;
    forn(i,0,3){
        if(vec[2*i].second == vec[2*i+1].second) return INF;
        resp += abs(vec[2*i].first - vec[2*i+1].first);
    }
    return resp;
}

ll ooo = 0;
ll ooi = 1;
ll oio = 2;
ll ioo = 4;
ll oii = 3;
ll ioi = 5;
ll iio = 6;
ll iii = 7;

int main(){
    _;
    ll n; cin >> n;
    vector<p64> v(2*n);
    forn(i, 0, 2*n) cin >> v[i].first, v[i].second = i/2;
    sort(v.rbegin(), v.rend());

    vector<v64> dp(max(2*n, 3ll), v64(8));
    dp[0][ooo] = 0;
    dp[0][ooi] = INF;
    dp[0][oio] = 0;
    dp[0][ioo] = 0;
    dp[0][oii] = INF;
    dp[0][ioi] = INF;
    dp[0][iio] = 0;
    dp[0][iii] = INF;

    dp[1][ooo] = 0;
    dp[1][ooi] = INF;
    dp[1][oio] = INF;
    dp[1][ioo] = 0;
    dp[1][oii] = paire(v[1], v[0]);
    dp[1][ioi] = INF;
    dp[1][iio] = INF;
    dp[1][iii] = paire(v[1], v[0]);;
    
    dp[2][ooo] = 0;
    dp[2][ooi] = INF;
    dp[2][oio] = INF;
    dp[2][ioo] = INF;
    dp[2][oii] = paire(v[2], v[1]);
    dp[2][ioi] = paire(v[2], v[0]);
    dp[2][iio] = paire(v[0], v[1]);
    dp[2][iii] = INF;

    forn(i, 3, 2*n) {
        dp[i][ooo] = dp[i-1][ioo];
        dp[i][oio] = dp[i-1][ioi];
        dp[i][ioo] = dp[i-1][iio];
        dp[i][iio] = dp[i-1][iii];
        
        dp[i][ooi] = dp[i-1][ooo] + paire(v[i], v[i-3]);
        dp[i][oii] = dp[i-1][ooi] + paire(v[i], v[i-3]);
        dp[i][ioi] = dp[i-1][oio] + paire(v[i], v[i-3]);
        dp[i][iii] = dp[i-1][oii] + paire(v[i], v[i-3]);

        dp[i][ioi] = min(dp[i][ioi], dp[i-1][ioo] + paire(v[i], v[i-2]));
        dp[i][oii] = min(dp[i][oii], dp[i-1][ioo] + paire(v[i], v[i-1]));
        dp[i][iii] = min(dp[i][iii], dp[i-1][ioi] + paire(v[i], v[i-2]));
        dp[i][iii] = min(dp[i][iii], dp[i-1][iio] + paire(v[i], v[i-1]));
    }
    cout << dp[2*n-1][iii] << ln;
} 