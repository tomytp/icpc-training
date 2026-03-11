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

bool solve(v64& v, v64& t) {
    debugv(v);
    if (*max_element(v.begin(), v.end()) > *max_element(t.begin(), t.end())) return false;
    if (sz(v) < sz(t)) return false;
    if (sz(v) == sz(t)) return v == t;

    ll n = sz(v);
    forn(i, 1, n) {
        ll nz = max(i, n-i); 
        if (nz < sz(t)) continue;
        v64 temp(nz);
        for (ll j = nz-1, idx = i-1; j >= 0 && idx >= 0; j--, idx--) {
            temp[j] += v[idx];
        }
        
        for (ll j = nz-1, idx = i; j >= 0 && idx < n; j--, idx++) {
            temp[j] += v[idx];
        }
        if (solve(temp, t)) return true;
    }
    return false; 
}

int main() {
    _;
    
    ll n; cin >> n;
    v64 a(n); 
    forn(i, 0, n) cin >> a[i];
    ll m; cin >> m;
    v64 b(m);
    forn(i, 0, m) cin >> b[i];
    
    bool x = solve(a, b);
    reverse(a.begin(), a.end());
    x |= solve(a, b);
    cout << (x ? "S" : "N") << ln;

    return 0;
}