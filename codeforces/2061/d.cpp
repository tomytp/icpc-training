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
    ll n, m; cin >> n >> m;
    multiset<ll> a, b;
    forn(i, 0, n) {
        ll x; cin >> x;
        a.insert(-x);
    }

    forn(i, 0, m) {
        ll x; cin >> x;
        b.insert(-x);
    }

    while (sz(b) && sz(a)) {
        debug(sz(a));
        debug(sz(b));
        ll va = -(*a.begin());
        ll vb = -(*b.begin());
        debug(va);
        debug(vb);

        if (sz(b) > sz(a)) {
            cout << "No\n";
            return;
        }

        if (va == vb) {
            a.erase(a.begin());
            b.erase(b.begin());
            continue;
        }
        if (va > vb) {
            cout << "No\n";
            return;
        }
        b.erase(b.begin());
        b.insert(-(vb/2));
        b.insert(-((vb+1)/2)); 
    }
    if (sz(a) || sz(b)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
