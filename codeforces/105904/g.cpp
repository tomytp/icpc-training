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
    string mt = "BR-SP";
    if (s[3] != 'S' && s[3] != '?') {
        cout << "N\n";
        return 0;
    }
    if (s[4] != 'P' && s[4] != '?') {
        cout << "N\n";
        return 0;
    }
    if (s[4] == 'P' && s[3] == 'S') {
        cout << "S\n";
        return 0;
    }
    cout << "T\n";
    return 0;
}