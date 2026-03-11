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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll w, h; 
ll qur= 0;

    ll cb = 0;
    ll bx = 1;

bool build(ll x, ll y) {
    if (qur == 11998) {
        cout << "! " << bx << " " << cb << endl;
        exit(0);
    }
    cout << "? " << x << " " << y << endl;
    string s; cin >> s;
    qur++;

    if (s[0] == 'b' && y == h) {
        cout << "! " << x << " " << y << endl;
        exit(0);
    }

    return s[0] == 'b';
}

ll bs(ll x, ll l) {
    ll r = h;
    ll ans = l;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (build(x, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}


int main() {
    _;
    cin >> w >> h;
    v64 v(w);
    iota(v.begin(), v.end(), 1ll);
    shuffle(v.begin(), v.end(), rng);

    forn(i, 0, w) {
        if (build(v[i], cb+1)) {
            cb = bs(v[i], cb+1);
            bx = v[i];
        }
    }
    cout << "! " << bx << " " << cb << endl;
    return 0;
}