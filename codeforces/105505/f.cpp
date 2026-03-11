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
    ll k, n; cin >> k >> n;
    if (k*3 < n || (k*2) - 1 > n) {
        cout << "*\n";
        return 0;
    }

    string ans;
    while(n) {
        if (n > 2*k && n >= 3) {
            ans += "-X-";
            n -= 3;
            k -= 1;
        } else {
            ans.push_back('-');
            n--;
        }
    }

    if (ans[0] == 'X' && ans[1] == 'X') {
        ans.erase(ans.begin());
        ans.push_back('X');
    }
    cout << ans << ln;
    return 0;
}