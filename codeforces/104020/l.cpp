#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
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
#define sq(x) ((x)*(x))

const ll INF = 0x3f3f3f3f3f3f3f3ll;

long double dist(v64 a, v64 b) {
    return sqrt(sq(a[0]-b[0]) + sq(a[1]-b[1]) + sq(a[2]-b[2]));
}

int main() {
    _;
    ll n; cin >> n;
    vector<v64> pts;
    forn(i, 0, n) {
        ll a, b, c; cin >> a >> b >> c;
        pts.push_back({a, b, c});
    }

    sort(pts.begin(), pts.end());
    
    long double best = 2e18;
    forn(i, 0, n) {
        forn(j, i+1, min(n, i+100)) {
            long double d = dist(pts[i], pts[j]);
            best = min(best, d);
        }
    }
    cout << fixed << setprecision(20) << best << ln;

    return 0;
}