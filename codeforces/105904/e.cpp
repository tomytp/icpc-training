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

int main(){
    _;
    ll n, d; cin >> n >> d;
    vector<p64> v(n);
    forn(i, 0, n) cin >> v[i].first >> v[i].second;
    v64 resp_frente(n, 0);
    v64 cum_frente(n, 0);
    v64 cum_tras(n, 0);
    v64 resp_tras(n, 0);

    sort(v.begin(), v.end());

    ll p1 = 0; ll p2 = 0;
    ll curr = 0;

    while (p1 < n){
        while(p2 < n && (abs(v[p2].first - v[p1].first) <= d)){
            curr += v[p2].second;
            p2++;
        }
        resp_frente[p1] = curr;
        curr -= v[p1].second;
        p1++;
    }
    
    p1 = n-1; 
    p2 = n-1;
    
    curr = 0;

    while (p1 >= 0){
        while(p2 >= 0 && (abs(v[p1].first - v[p2].first) <= d)){
            curr += v[p2].second;
            p2--;
        }
        resp_tras[p1] = curr;
        curr -= v[p1].second;
        p1--;
    }
    
    cum_frente[n-1] = resp_frente[n-1];
    cum_tras[0] = resp_tras[0];

    for(ll i = n-2; i >= 0; i--)  cum_frente[i] = max(resp_frente[i], cum_frente[i+1]);
    forn(i,1,n)                   cum_tras[i] = max(resp_tras[i], cum_tras[i-1]);
    

    p1 = 0; 
    p2 = 0;
    curr = 0;
    ll resp = 0;

    // forn(i,0,n) {cout << resp_frente[i] << " ";} cout << ln;
    // forn(i,0,n) {cout << cum_frente[i] << " ";} cout << ln;
    // forn(i,0,n) {cout << resp_tras[i] << " ";} cout << ln;
    // forn(i,0,n) {cout << cum_tras[i] << " ";} cout << ln;
    while (p1 < n){
        while(p2 < n && (abs(v[p2].first - v[p1].first) <= d)){
            curr += v[p2].second;
            p2++;
        }
        
        ll aux = 0;
        if(p1 > 0) aux = max(aux, cum_tras[p1-1]);
        if(p2 < n) aux = max(aux, cum_frente[p2]);

        resp = max(resp, curr+aux);
        curr -= v[p1].second;
        p1++;
    }
    
    cout << resp << ln;
    return 0;
}