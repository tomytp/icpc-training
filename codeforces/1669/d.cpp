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

bool possible(string buffer) {
    ll b = 0, r = 0;
    forn(i, 0, buffer.size()) {
        if (buffer[i] == 'B') b++;
        else r++;
    }
    if (b && r) return true;
    else return false;
}

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    string buffer = "";
    forn(i, 0, n) {
        if (s[i] == 'W' && buffer.size() > 0) {
            if (!possible(buffer)) {
                cout << "NO" << ln;
                return;
            }
            buffer = "";
        }
        if (s[i] != 'W') buffer += s[i];
    }
    if (buffer.size() && !possible(buffer)) {
        cout << "NO" << ln;
    } else {
        cout << "YES" << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}