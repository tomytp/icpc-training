#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

template<typename T>
struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;
    T val;

    static constexpr T neutral = INF;

    node(ll l_, ll r_, const vector<T>& v) : lm(l_), rm(r_) {
        if (lm == rm) {
            val = v[lm];
        } else {
            ll m = (lm + rm) / 2;
            lc = make_unique<node>(lm, m, v);
            rc = make_unique<node>(m + 1, rm, v);
            pull();
        }
    }
    static T comb(const T& a, const T& b) {
        return std::min(a, b);
    }
    void pull() { val = comb(lc->val, rc->val); }

    void point_set(ll idx, T x) {
        if (lm == rm) { val = x; return; }
        (idx <= lc->rm ? lc : rc)->point_set(idx, x);
        pull();
    }
    T query(ll lq, ll rq) {
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }

    ll first_le(ll lq, T x, ll n) {
        if (rm < lq || val > x) return n;
        if (lm == rm)   return lm;
        ll res = lc->first_le(lq, x, n);
        return res != n ? res : rc->first_le(lq, x, n);
    }
};

struct Loss {
    ll rnd, pos, bv;
};

void solve() {
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];

    vector<Loss> losses;
    ll i=0, j=0, rnd=0, score0=0;

    while (rnd < n){
        if (a[i] > b[j]) {
            score0++;
            i++;
        } else {
            losses.push_back({rnd, i, b[j]});
            j++;
        }
        rnd++;
    }

    v64 max_suff(n+1, -1);
    for (ll k = n-1; k >= 0; k--) max_suff[k] = max(a[k], max_suff[k+1]);

    auto seg = node<ll>(0, n-1, a);

    ll best = score0;
    forn(idx, 0, (ll)losses.size()) {
        ll pos = losses[idx].pos;
        ll bv = losses[idx].bv;
        ll rndLoss = losses[idx].rnd;

        if (pos+1 >= n) continue;
        if (max_suff[pos+1] <= bv) continue;

        ll nx_round = (idx+1 < (ll)losses.size()) ? losses[idx+1].rnd : n;
        ll winsrev = nx_round - rndLoss - 1;

        ll firstBad = seg.first_le(pos+1, bv, n);
        ll rem = n - rndLoss - 1;
        ll runLen = min(firstBad - (pos+1), rem);

        ll idx_end = pos + 1 + runLen;
        bool outside = (idx_end < n && max_suff[idx_end] > bv);

        ll delta = runLen - winsrev + (outside ? 1 : 0);
        best = max(best, score0 + delta);
    }

    cout << best << ln;
}


int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
