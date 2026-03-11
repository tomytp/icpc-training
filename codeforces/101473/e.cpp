#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll a, b; cin >> a >> b;
    vector<bool> v(a+1);
    forn(i,0, b) {
        ll x; cin >> x;
        v[x] = true;
    }
    forn(i, 1, a+1) {
        if (!v[i]) cout << i << " ";
    }

    if (b == a) cout << "*";
    cout << ln;

    return 0;
}