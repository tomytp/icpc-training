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
mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

bool valid(v64& a, v64& b) {
    ll n = a.size();
    forn(i, 0, n) if (a[i] == b[i]) return false;
    return true;
}

int main(){
    _;
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    if (n == 2) {
        cout << "IMPOSSIBLE" << ln;
        return 0;
    }
    v64 c(n);
    iota(c.begin(), c.end(), 1ll);

    while (!valid(a, c) || !valid(b, c)) {
        shuffle(c.begin(), c.end(), rng);
    }

    forn(i, 0, n) cout << c[i] << " \n"[i==n-1];
    return 0;
}