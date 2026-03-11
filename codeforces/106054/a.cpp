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
    string s; cin >> s;
    ll n = s.size();
    ll state = 0;
    forn(i, 0, n) {
        if (state == 0 && s[i] == 'T') state = 1;
        if (state == 1 && s[i] == 'A') state = 2;
        if (state == 2 && s[i] == 'P') state = 3;
    }

    cout << (state == 3 ? "S\n" : "N\n");
    
    return 0;
}
