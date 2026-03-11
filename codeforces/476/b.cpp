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
    string a, b; cin >> a >> b;

    ll expected = 0;
    forn(i, 0, a.size()) if (a[i] == '+') expected++; else expected--;
    
    map<ll, ll> cnt;
    ll tot = 0;
    function<void (ll, ll)> solve = [&](ll idx, ll cur) {
        if (idx == b.size()) {
            cnt[cur]++;
            tot++;
            return;
        }
        if (b[idx] == '+') {
            solve(idx + 1, cur + 1);
        } else if (b[idx] == '-') {
            solve(idx + 1, cur - 1);
        } else {
            solve(idx + 1, cur + 1);
            solve(idx + 1, cur - 1);
        }
    };

    solve(0, 0);
    debug(cnt[expected]);
    debug(tot);
    cout << setprecision(20) << (long double) cnt[expected] /  (long double)tot << ln;
    return 0;
}