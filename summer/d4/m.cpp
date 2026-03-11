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

const ll N = 3999;
v64 lp(N+1), pr;

void sieve(){
    forn(i, 2, N+1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

bool solve(){
    ll n; cin >> n;
    ll p1 = -1, p2 = -1;
    for(auto p : pr){
        ll e =0;
        while(n%p == 0){
            n/=p;
            e++;
        }
        if(e == 1){
            if(p1 == -1) p1 = p;
            else if( p2 == -1) p2 = p;
        }
        if(e>=2){
            if(p1 == -1) p1 = p;
            if( p2 == -1) p2 = p; 
        }
    }
    debug(n);
    debug(p1);
    debug(p2);
    if(n!=1)return false;
    if(p2 == -1) return true;
    if(p1*p2 <= N) return false;
    return true;
}

int main(){
    sieve();
    for(auto p : pr) cout << p << " ";
    ll t; cin >> t;
    forn(i, 0, t) cout << solve() << ln;
    return 0;
}