#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    if (accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)) {
        cout << "impossible" << ln;
        return 0;
    }

    forn(i, 0, n) {
        if (a[i] == 0 && b[i] == 0) {
            cout << "impossible" << ln;
            return 0;
        }
        if (a[i] > n-1 || b[i] > n-1) {
            cout << "impossible" << ln;
            return 0;
        }
    }

    


    return 0;
}