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

bool solve(v64 &v, ll c, ll t){
    ll consec = 0, best = 0; 
    if(v[0] < t) consec++;
    forn(i, 1, v.size()){
        debug(v[i]);
        debug(t); 
        if(v[i] >= t){
            best = max(consec, best);
            consec = 0;
            continue;
        }
        consec++;
    }
    best = max(consec, best);

    debug(best);
    debug(c);

    return (best <= c);
}

int main() {
    _; ll n, c; cin >> c >> n;
    vector<ll> v(n);
    forn(i, 0, n) cin >> v[i];

    ll r = 50, l = -50, ans;
    while(l <= r){
        ll mid = (l+r)/2;
        debug(mid);
        bool aux = solve(v, c, mid);
        if(aux){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    if(solve(v, c, l)) ans = max(ans, l);
    if(solve(v, c, r)) ans = max(ans, r);

    cout << ans << ln;
    return 0;
}