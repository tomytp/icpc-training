#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

bool testa(ll d, v64& vec, ll n, ll m){
    ll curr = m;
    forn(i,0,n){
        if(curr < vec[i]) return false;
        curr -= vec[i];
        if(curr < d) curr = m;
    }
    return true;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    v64 vec(n);
    forn(i,0,n) cin >> vec[i];
    ll l = 0;
    ll r = m;
    ll ans = m;

    while(l <= r){
        ll mid = (l+r)/2;
        if(testa(mid, vec, n , m)){
            r = mid-1;
            ans = mid;
        } else{
            l = mid+1;
        }
    }

    cout << ans << ln;
    return;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
}