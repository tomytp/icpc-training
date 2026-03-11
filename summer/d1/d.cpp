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
 
void solve() {
    ll zeros, ones, orr; cin >> zeros >> ones >> orr;
    ll andd = (zeros+ones-1-orr);
    if(zeros + ones == 1){
        cout << 0 << ln;
        return;
    }
    ll maxor = 2*min(zeros, ones) -1 + (zeros > ones);
    ll trueor = min(maxor, orr);
    if(trueor < 0) trueor = 0;
    ones = ones - (trueor+1)/2 + (trueor > 0); 
    andd += orr - trueor;
    ll trueand = min(andd, ones-1);
    if(trueand < 0) trueand = 0;
    debug(trueor);
    debug(trueand);
    cout << trueor + trueand << ln;  
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}