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
    ll n; cin >> n;
    vector<v64> v(n);
    set<ll> tipos;
    forn(i, 0, n) {
        ll k; cin >> k;
        forn(j, 0, k) {
            ll x; cin >> x;
            tipos.insert(x);
            v[i].push_back(x);
        }
    }
    if (n != 2) {
        cout << "S\n";
        return 0;
    }

    if (tipos.size() == 1) {
        cout << "S\n";
        return 0;
    }

    for(ll i = (ll)v[1].size() - 1; i >= 0; i--) {
        v[0].push_back(v[1][i]);
    }

    ll flips = 0;
    forn(i, 1, v[0].size()) {
        if (v[0][i-1] != v[0][i]) flips++;
    }

    if (flips <= 1) {
        cout << "S\n";
        return 0;
    } else {
        cout << "N\n";
        return 0;
    }

    return 0;
}