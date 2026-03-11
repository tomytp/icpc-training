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
    ll n, k; cin >> n >> k;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];

    ll cur_p = max(v[0], v[1]);
    ll cur_k = 1;

    forn(i, 2, n) {
        if (cur_p > v[i]) cur_k++;
        else {
            cur_p = v[i];
            cur_k = 1;
        }

        if (cur_p == n) {
            cout << n << ln;
            return 0;
        }
        if (cur_k >= k) {
            cout << cur_p << ln;
            return 0;
        }
    }

    cout << n << ln;


    return 0;
}