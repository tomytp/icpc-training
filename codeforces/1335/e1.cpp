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

void solve() {
    ll n; cin >> n;
    v64 v(n); forn(i, 0, n) cin >> v[i];
    v64 a(201), b(201), c(201);
    forn(i, 0, n) b[v[i]]++;

    ll ans = 0;
    forn(i, 0, (n/2)) {
        ll b_max = 0;
        ll c_max = 0;
        forn(j, 0, 201) {
            b_max = max(b_max, b[j]);
            c_max = max(c_max, min(a[j], b[j]));
        }
        ans = max(ans, 2*c_max + b_max);
        c[v[i]]++;
        a[v[n-1-i]]++;
        b[v[i]]--;
        b[v[n-1-i]]--;
    }

    cout << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}