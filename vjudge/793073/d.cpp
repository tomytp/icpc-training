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

ll dist(ll x, ll y) {
    return x*x + y*y;
}

int main() {
    _;
    ll r; cin >> r;

    ll d0 = r*r;
    
    ll x = r+1;
    ll bx, by, b = INF;
    forn(y, 0, r+1) {
        while (x >= 0 && dist(x, y) > d0) x--;
        x++;
        if (dist(x, y) < b) bx = x, by = y, b = dist(x, y);
    }

    cout << bx << " " << by << ln;


    return 0;
}
