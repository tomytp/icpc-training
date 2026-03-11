#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll solve(v64& vec, ll t1, ll t2, ll n){
    v64 dp(n);
    debugv(vec);
    forn(i,0,n){
        ll aux = INF;
        for(ll x : {t1, t2}){
            debug(vec[i]-x);
            ll idx = lower_bound(vec.begin(), vec.end(), vec[i]-x)-vec.begin();
            idx--;
            debug(idx);
            aux = min(aux, (idx == -1 ? 0 : dp[idx]) + x);
        }
        dp[i] = aux;
    }
    debugv(dp);
    return dp[n-1];
}

int main() {
    _;
    ll n, c, t1, t2;
    cin >> n >> c >> t1 >> t2;
    v64 vec(n);
    forn(i,0,n) cin >> vec[i];

    ll resp = INF;

    forn(i,0,n){
        debug(i);
        v64 aux = vec;
        forn(j,0,n){
            aux[j] = (c + vec[j] - vec[i])%c;
        }
        sort(aux.begin(), aux.end());
        resp = min(resp ,solve(aux, t1, t2, n));
        trace(cout << ln;);
    }

    cout << resp << ln;
    return 0;
}