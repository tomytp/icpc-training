#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main() {
    ll n, k; cin >> n >> k;
    v64 v(n); forn(i, 0, n ) cin >> v[i];
    ll st = (k + 1) /2;
    ll nd = k - st;
    if (k & 1) {
        swap(st, nd);
        reverse(v.begin(), v.end());
    }
    
    forn(i, st, n-nd) {
        cout << v[i] << " \n"[i==(n-nd-1)];
    }
    return 0;
}