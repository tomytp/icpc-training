#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
#else
    #define _ (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;


void solve(){
    string s;
    cin >> s;
    ll resp = 0;
    ll sign = 1;
    while(s.size() >= 3){
        ll n = s.size();
        ll aux = s[n-1] - '0';
        aux += 10*(s[n-2] - '0');
        aux += 100*(s[n-3] - '0');
        s.pop_back();
        s.pop_back();
        s.pop_back();
        resp += sign*aux;
        sign *= -1;
    }

    if(s.size() == 1){
        ll n = s.size();
        ll aux = s[n-1] - '0';
        resp += sign*aux;
    }

    if(s.size() == 2){
        ll n = s.size();
        ll aux = s[n-1] - '0';
        aux += 10*(s[n-2] - '0');
        resp += sign*aux;
    }
    cout << abs(resp) << " " << (resp%13 == 0 ? "YES":"NO") << ln;
}

int main() {
    _;
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}