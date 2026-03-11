#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ll n; cin >> n;
    ll sum = 0;
    forn(i, 0, n){
        ll a; cin >> a;
        sum += a;
    }

    for(ll i = n; i>0; i--){
        if(sum%i == 0){
            cout << n-i << ln;
            return 0;
        }
    }
    return 0;
}