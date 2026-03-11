#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll n, p, h;
v64 mult;
v64 sum;
ll att = 0;
ll totsum = 0;
ll totmult = 1;


int main() {
    _;
    cin >> n >> p >> h;

    forn(i,0,n){
        char c;
        cin >> c;
        if(c == '!'){
            att++;
        }else if(c == '*'){
            ll x; cin >> x;
            mult.push_back(x);
            totmult *= x;
        } else if(c == '+'){
            ll x; cin >> x;
            sum.push_back(x);
            totsum += x;
        }
    }

    sort(mult.rbegin(), mult.rend());
    sort(sum.rbegin(), sum.rend());
    
    if((p == 0 && totsum == 0) || att == 0){
        cout << '*' << ln;
        return 0;
    }

    ll ans = 0;

    ll prox = (p + totsum)*totmult;

    while (true){   
        if(att*prox < h) break;
        ans += n;
        p = prox;
        h -= att*prox;
        prox = (p + totsum)*totmult;
    }

    ll best = INF;
 
    forn(qs, 0, sum.size()+1){
        forn(qm, 0, mult.size()+1){
            forn(qa, 1, att+1){ 
                ll temp = p;
                forn(i,0,qs){
                    temp += sum[i];
                }
                forn(i,0,qm){
                    temp *= mult[i];
                }
                temp *= qa;
                if(h <= temp){
                    best = min(best, qs+qm+qa);
                }
            }
        }
    }

    cout << ans + best << ln;
    return 0;
}