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

struct show{
    ll i, f, o, p;
    void print(){
        cout << i << " " << f << " " << o << " " << p << ln;
    }
};

int main(){
    _;
    ll n; cin >> n;
    ll pot2 = 1 << n;
    set<ll> set_eventos;

    map<ll, vector<show>> mp;
    vector<vector<show>> termina_agora(86410);

    forn(i,0,n){
        ll m; cin >> m;
        forn(j,0,m){
            show s;
            cin >> s.i >> s.f >> s.o;
            s.p = i;
            set_eventos.insert(s.i);
            set_eventos.insert(s.f);
            termina_agora[s.f].push_back(s);
        }
    }

    ll t = set_eventos.size();
    v64 eventos(t);
    map<ll,ll> reverse;

    ll idx = 0;
    for(ll p: set_eventos) eventos[idx++] = p;

    forn(i,0,t) reverse[eventos[i]] = i;

    vector<v64> dp(pot2, v64(t+1,-1));

    forn(i,0,t+1) dp[0][i] = 0;
    
    forn(i,0,t){
        forn(mask, 0, pot2) dp[mask][i] = max(dp[mask][i], (i == 0 ? -1 : dp[mask][i-1]));

        for(show s: termina_agora[eventos[i]]){ 
            forn(mask,0,pot2){
                if(dp[mask][reverse[s.i]] == -1) continue;
                ll aux = dp[mask][reverse[s.i]] + s.o;
                dp[mask|(1<<s.p)][i] = max(dp[mask|(1<<s.p)][i], aux);
            }
        }
    }
    
    cout << dp[pot2-1][t-1] << ln;
    return 0;
}