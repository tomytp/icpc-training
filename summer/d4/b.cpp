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
const ll MOD = 998244353;

int main(){
    _;
    ll n, m;
    cin >> n >> m;
    v64 d1, d2, t1, t2;

    ll sd1 = 0;
    ll sd2 = 0;
    forn(i,0,n){
        ll x; cin >> x;
        char c; cin >> c;
        if(c == 'T'){
            t1.push_back(x);
        }else{
            d1.push_back(x);
            sd1 += x;
        }
    }

    forn(i,0,m){
        ll x; cin >> x;
        char c; cin >> c;
        if(c == 'T'){
            t2.push_back(x);
        }else{
            d2.push_back(x);
            sd2 += x;
        }
    }

    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());

    if(sd1 > sd2){
        swap(sd1, sd2);
        swap(n, m);
        swap(d1, d2);
        swap(t1, t2);
    }

    debugv(d1);
    debugv(t1);
    debugv(d2);
    debugv(t2);

    ll resp = 1;

    if(sz(t1) > 0){ 
        ll tmin = sd2 - sd1;
        ll idx = upper_bound(t1.begin(), t1.end(), tmin) - t1.begin();
        resp = sz(t1)-idx;
    }

    debug(resp);

    forn(i,1,sz(t1)) resp = (resp*i)%MOD;
    forn(i,1,sz(t2)+1) resp = (resp*i)%MOD;
    forn(i,1,sz(d1)+1) resp = (resp*i)%MOD; 
    forn(i,1,sz(d2)+1) resp = (resp*i)%MOD;

    cout << resp << ln;
    return 0;
}