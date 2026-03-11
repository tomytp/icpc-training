#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

class box{
    
}
void solve(){
    ll n, k; cin >> n >> k;
    ll x2i = 0, x1i= INF, y2i = 0, y1i = INF;
    map<ll, vector<ll>> sweepline;
    forn(i, 0, n){
        ll a, b, c, d; cin >> a >> b >> c >> d; c--; d--;
        x1i = min(x1i, a);
        x2i = max(x2i, c);
        y1i = min(y1i, b);
        y2i = max(y2i, d);
        
        sweepline[b].push_back(c-a+1);
        sweepline[d+1].push_back(-(c-a+1)); 
    }

    debug(x1i);
    debug(x2i);
    debug(y1i);
    debug(y2i);

    ll active = 0, l = 0, best = 0;
    for(auto &[t, v] : sweepline){
        for(auto x : v){
            debug(x);
            if(x < 0) active--; 
            else active++;

            l += x;
        }
        debug(t);
        debug(active);
        debug(l);
        best = max(best, l + (active-1)*k);
    }
    ll delta = ((x2i-x1i+1) - best)*(y2i - y1i +1);
    cout << max(delta, (ll)0) << ln;
}

int main() {
    _; ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}