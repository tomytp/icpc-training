#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz ((ll) (x).size())
#define ln "\n"

int main() {
    ll x; cin >> x;
    ll h = x/2;
    if(x == 0) h = 1;
    if(x == 1) h = 2;
    if(x == -1) h = -2;
    cout << h << " " << x-h << ln;
    return 0;
}