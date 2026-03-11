#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

void solve() {
    ll n, k; cin >> n >> k;
    ll x = 0;
    ll aux;
    forn(i, 0, k) cin >> aux;
    forn(i, k, n) cin >> aux, x |= aux;
    cout << x << ln;
}

int main() {
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}