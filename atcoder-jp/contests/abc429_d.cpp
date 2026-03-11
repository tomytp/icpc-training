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

struct event {
    ll pos = 0, cnt = 0, acc = 0;
};

int main(){
    _;
    ll n, m, c; cin >> n >> m >> c;
    v64 v(n); forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    vector<event> vp;
    forn(i, 0, n) {
        if (vp.size() && vp.back().pos == v[i]) {
            vp.back().cnt++;
        } else {
            vp.push_back({v[i], 1});
        }
    }

    forn(i, 0, n) {
        if (vp.size() && vp.back().pos == v[i] + m) {
            vp.back().cnt++;
        } else {
            vp.push_back({v[i] + m, 1});
        }
    }

    ll ans = 0;
    ll acc = 0;
    ll nd = 0;

    ll subn = vp.size() / 2;
    forn(st, 0, subn) {
        while (acc < c) {
            acc += vp[nd++].cnt;
        }
        ll mult;
        if (st == 0) {
            mult = 2*m - (vp[vp.size() - 1].pos - vp[st].pos);
        } else {
            mult = vp[st].pos - vp[st-1].pos;
        }
        ans += acc * mult;
        debug(acc);
        debug(mult);
        acc -= vp[st].cnt;
    }

    cout << ans << ln;
    return 0;
}