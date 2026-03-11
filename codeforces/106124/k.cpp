#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz ((ll) (x).size())
#define ln "\n"

ll convert(string s){
    if(s.size() == 3){
        return 100*(s[0]-'0')+10*(s[1]-'0')+s[2]-'0';
    }
    return 10*(s[0]-'0')+s[1]-'0';

}

int main() {
    ll n; cin >> n;
    ll currmax = 10;

    forn(i,0,n){
        string s; cin >> s;
        if(s[0] == '/'){
            cout << currmax << ln;
            continue;
        }
        ll aux = convert(s);
        cout << aux << ln;
        // cout << "$$ " << 10*((aux+9)/10) << ln;
        currmax = max(currmax, 10*((aux+10)/10));
    }
    return 0;
}