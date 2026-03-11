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
    ll n; cin >> n;
    v64 v(n), v2(n);
    forn(i, 0, n) {
        ll aux; cin >> aux;
        v[aux-1] = i;
    }

    ll ct = 1;
    forn(i, 1, n) {
        if (v[i] < v[i-1]) ct++;
    }
    ll divs = 0;
    while (ct > 1) {
        divs++;
        ct = (ct+1)/2;
        debug(ct);
    }

    cout << divs << ln;
    return 0;
}