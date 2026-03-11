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

bool full(ll l, ll r) {
    ll len = r - l + 1;
    return ((len & (len - 1)) == 0) && ((l & (len - 1)) == 0);
}

ll rec(ll l, ll r) {
    if (l == r) return 1;

    if (full(l, r)) return (r - l + 1);

    ll diff = l ^ r;
    int k = 63 - __builtin_clzll(diff);
    
    ll split = (r >> k) << k;
    
    ll lend = split - 1;
    ll rstart = split;
    
    bool fl = full(l, lend);
    bool fr = full(rstart, r);
    
    ll lenl = lend - l + 1;
    ll lenr = r - rstart + 1;

    if (fl && fr) {
        if (lenl == lenr) return lenl + lenr;
        else return min(lenl, lenr);
    }
    else if (fl) return rec(rstart, r);
    else if (fr) return rec(l, lend);
    else return 1;
}

void solve() {
    ll l, r; cin >> l >> r;

    ll mask = l | (r + 1);
    ll tz = __builtin_ctzll(mask);

    ll res = rec(l >> tz, r >> tz);

    cout << (res << tz) - 1 << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}