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

int main() {
    _;
    ll n; cin >> n;
    v64 vec(n), acc(n);
    ll tot = 0;

    forn(i,0,n){
        cin >> vec[i];
        tot += vec[i];
        acc[i] = tot;
        
    }
    debugv(acc);
    if(tot%3 != 0){
        cout << 0 << ln;
        return 0;
    }
    ll arc = tot/3;

    map<ll, ll> mp;
    forn(i,0,n) mp[acc[i]%tot] = 1; 
    
    ll resp = 0;

    forn(i,0,n){
        ll a = acc[i];
        ll b = (a + arc)%tot;
        ll c = (b + arc)%tot;
        trace(cout << a << " " << b << " " << c << ln;);
        if(mp[b]*mp[c] == 1){
            debug(1);
            resp++;
        }
        trace(cout << ln;);
    }

    debug(resp);
    cout << resp/3 << ln;
    return 0;
}