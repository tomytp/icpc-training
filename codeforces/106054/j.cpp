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

vector<v64> torre1;
vector<v64> torre2;

int main(){
    _;
    ll t; cin >> t;
    torre1.resize(t);
    torre2.resize(t);
    map<ll, ll> mp1, mp2;

    forn(i,0,t){
        ll k; cin >> k;
        torre1[i].resize(k);
        forn(j,0,k){
            cin >> torre1[i][j];
            mp1[torre1[i][j]]++;
        }
    }
    
    forn(i,0,t){
        ll k; cin >> k;
        torre2[i].resize(k);
        forn(j,0,k){
            cin >> torre2[i][j];    
            mp2[torre2[i][j]]++;
        }
    }

    if (mp1 != mp2) {
        cout << "N\n";
        return 0;
    }

    if (t == 2) {
        reverse(torre1[1].begin(), torre1[1].end());
        reverse(torre2[1].begin(), torre2[1].end());
        for(auto x : torre1[1]) torre1[0].push_back(x);
        for(auto x : torre2[1]) torre2[0].push_back(x);
        
        if (torre1[0] == torre2[0]) {
            cout << "S\n";
        } else {
            cout << "N\n";
        }

    } else {
        cout << "S\n";
    }

    return 0;
}
