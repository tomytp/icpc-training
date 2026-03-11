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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll z = 0, ones = 0;
    forn(i, 0, n) {
        if (s[i] == '1') ones++;
        else z++;
    }

    while (k) {
        while (z >= 1 && z > ones && k) {
            k--;
            z -= 2;
        }

        while (ones >= 1 && ones > z && k) {
            k--;
            ones -= 2;
        }

        if (z == ones && z >= 2 && k) {
            z -= 2;
            k--;
        }
        if (z < 2 && ones < 2 && k) {
            cout << "NO" << ln;
            return;
        }
    }


    if (abs(z- ones) > 1) {
        cout << "NO" << ln;
    } else {
        cout << "YES" << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}