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

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    ll li = 0, ri = n-1;
    ll ltot = 0, rtot = 0;
    ll lcurr = 0, rcurr = 0;
    ll counter = 0;
    while (true) {
        lcurr = 0;
        counter++;
        while (lcurr <= rcurr && li <= ri) {
            lcurr += v[li++];
        }
        ltot += lcurr;
        if (li > ri) break;
        rcurr = 0;
        counter++;
        while(rcurr <= lcurr && ri >= li) {
            rcurr += v[ri--];
        }
        rtot += rcurr;
        if (li > ri) break;
    }
    cout << counter << " " << ltot << " " << rtot << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}