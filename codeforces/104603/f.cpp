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

long double dist(ll x, ll y, ll xx, ll yy) {
    return sqrtl((x-xx)*(x-xx) + (y-yy)*(y-yy));
}

int main() {
    _;
    ll n; cin >> n;
    ll w, l, tx, ty; cin >> w >> l >> tx >> ty;
    vector<long double> a(n), b(n);
    forn(i, 0, n) {
        ll x, y; cin >> x >> y;
        a[i] = dist(x, y, tx, ty);
    }
    forn(i, 0, n) {
        ll x, y; cin >> x >> y;
        b[i] = dist(x, y, tx, ty);
    }    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string winner;
    ll pts = 0;
    debug(a[0]);
    debug(b[0]);
    if (a[0] < b[0]) {
        winner = "A";
        ll i = 0;
        while (i < n && a[i] < b[0]) {
            pts++;
            i++;
        } 

    } else {
        winner = "R";
        ll i = 0;
        while (b[i] < a[0]) {
            pts++;
            i++;
        } 
    }
    cout << winner << " " << pts << ln;
    return 0;
}