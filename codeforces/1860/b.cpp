#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve() {
    ll n, k, ai, ab; cin >> n >> k >> ai >> ab;

    ll boa = n/k;
    ll ruim = n%k;
    ll fruim = max(0ll, ruim - ai);
    ll nruim = max(0ll, ai - ruim); 
    ll fboa = max(0ll, boa - ab);
    ll rep = min(nruim / k, fboa); 
    cout << fruim + fboa - rep << ln;
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
