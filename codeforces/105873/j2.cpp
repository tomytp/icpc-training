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

bool valid(ll n, string& s) {
    if(n > (ll)s.size()) return false;
    if (n <= 1) return true;
    v64 count(26);
    ll odds = 0, evens = 26;
    forn(i, 0, n) {
        ll idx = s[i] - 'a';
        count[idx]++;
        if (count[idx] & 1) {
            odds++;
            evens--;
        } else {
            evens++;
            odds--;
        }
    }
    if (odds <= 1) {
        return true;
    }
    forn(i, n, s.size()) {
        ll idx = s[i] - 'a';
        count[idx]++;
        if (count[idx] & 1) {
            odds++;
            evens--;
        } else {
            evens++;
            odds--;
        }

        idx = s[i-n] - 'a';
        count[idx]--;
        if (count[idx] & 1) {
            odds++;
            evens--;
        } else {
            evens++;
            odds--;
        }
        if (odds <= 1) {
            return true;
        }
    }
    return false;
}

int main(){
    _;
    ll n; cin >> n;
    string s; cin >> s;

    for( ll i = n; i >= 0; i--) {
        if (valid(i, s)){
            cout << i << ln;
            return 0;
        }
    }
    return 0;
}