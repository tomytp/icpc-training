#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
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

set<ll> loop = {2, 4, 8, 6};
v64 looop = {2, 4, 6, 8};

ll starting_s;
ll kk;


ll pref(ll r){
    ll p = 0; forn(i, 0, r) p += looop[i];
    return p;
}

ll f(ll q, ll r){
    if (q < 0) return -1;
    ll x = 4*q + r;
    if (x < 0 || x > kk) return -1;
    ll ss = starting_s + 20*q + pref(r);
    return ss * (kk - x);
}

ll ternary_search(ll r_){
    ll l = 0, r = (kk - r_) / 4;
    if (r < 0) return -1;
    while (r - l > 3) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(m1, r_), f2 = f(m2, r_);
        if (f1 < f2) l = m1 + 1;
        else r = m2 - 1;
    }
    ll best = -1;
    for (ll q = l; q <= r; q++) best = max(best, f(q, r_));
    return best;
}

void solve() {
    long long s, k; cin >> s >> k;

    ll bst = 0;
    while(!loop.count(s%10) && s%10 != 0 && k) {
        bst = max(bst, (ll)k*s);
        s += s%10;
        k--;
    }
    bst = max(bst, (ll)k*s);
    if (!loop.count(s%10)) {
        cout << (long long)bst << ln;
        return;
    }

    if (k < 10) {
        while (k) {
            bst = max(bst, (ll)k*s);
            s += s%10;
            k--;
        }
        cout << (long long)bst << ln;
        return;
    }
    bst = max(bst, (ll)k*s);

    while (k && s%10 != 2) {
        bst = max(bst, (ll )k*s);
        s += s%10;
        k--;
    }
    bst = max(bst, (ll)k*s);

    kk = k;
    starting_s = s;

    ll best_cycle = 0;
    forn(r, 0, 4) best_cycle = max(best_cycle, ternary_search(r));
    bst = max(bst, best_cycle);

    cout << (long long)bst << ln;
}

int main(){
    _;
    long long t; cin >> t;
    while(t--) solve();
    return 0;
}