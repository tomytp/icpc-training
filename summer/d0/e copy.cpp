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

void classic(ll n, ll v){
    v64 dp(v+1,0);
    forn(i,0,n){
        ll peso, valor;
        cin >> peso >> valor;
        for(ll j = v; j >= peso; j--){
            dp[j] = max(dp[j], dp[j-peso] + valor);
        }
    }
    ll resp = 0;
    forn(i,0,v+1) resp = max(resp, dp[i]);
    cout << resp << ln;
}

int main(){
    _;
    ll n, v;
    cin >> n >> v;
    if(v <= 400){  
        classic(n, v);
        return 0;
    }

    vector<p64> vec(n);

    forn(i,0,n) cin >> vec[i].first;
    forn(i,0,n) cin >> vec[i].second;

    ll p1 = 0;
    ll p2 = n-1;
    ll ans = 0;
    ll best = 0;

    while(p1 < p2){
        if(vec[p2].first + vec[p1].first > v){
            p2--;
            continue;
        } 
        best = max(vec[p1].second, best);
        ans = max(ans, best + vec[p2].second);
        p1++;
    }

    
    ll c = (v-100)/3;
    ll r=  (v-100)%3;
    ll lim = 100+r;

    forn(i,0,n) vec[i].first -= c;

    vector<v64> dp(3, v64(lim+1));

    forn(i,0,n){
        auto[peso, valor] = vec[i];
        for(ll j = 2; j >= 1; j--){
            forn(x,0,lim+1){
                if(x-peso < 0) continue;
                dp[j][x] = max(dp[j][x], dp[j-1][x-peso] + valor);
            }
        }
        dp[0][peso] = max(dp[0][peso], valor);
    }

    forn(i,0,lim+1) ans = max(ans, dp[2][i]);
    cout << ans << ln;
    return 0;
}