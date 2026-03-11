#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void) 0
    #define debug(x) cout << __LINE__  << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    v64 vec(n), acc(n), acc2(n);

    forn(i,0,n){
        cin >> vec[i];
        acc[i] = vec[i] + (i != 0 ? acc[i-1] : 0);
        acc2[i] = acc[i] + (i != 0 ? acc2[i-1] : 0);
    }

    ll resp = acc2[n-1];

    forn(i,1,n){
        resp += acc2[n-1] - acc2[i-1] - (n-i)*acc[i-1];
    }

    cout << resp << ln;
    return 0;
}