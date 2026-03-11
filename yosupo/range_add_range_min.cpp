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

// Segment Tree (Range Query + Point Update)
//
// Balanced binary tree for range queries with a customizable combine; supports point updates and range queries.
//
// complexity: O(log N) per op, O(N)

template<typename T>
struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;

    static constexpr T neutral = INF; // e.g., 0 for sum, INF for min, etc.
    T val = neutral;
    T lazy_add = T();
    optional<T> lazy_set = nullopt;

    node(ll lm_, ll rm_, const vector<T>& v) : lm(lm_), rm(rm_) {
        if (lm == rm) val = v[lm];
        else {
            ll mid = (lm + rm) / 2;
            lc = make_unique<node>(lm, mid, v);
            rc = make_unique<node>(mid + 1, rm, v);
            pull();
        }
    }

    void push() {
        if (lazy_set.has_value()) {
            val = *lazy_set;
            if (lm != rm) {
                lc->lazy_set = rc->lazy_set = lazy_set;
                lc->lazy_add = rc->lazy_add = T();
            }
            lazy_set.reset();
        }
        if (lazy_add != T()) {
            val += lazy_add;
            if (lm != rm) {
                if (lc->lazy_set) *lc->lazy_set += lazy_add;
                else lc->lazy_add += lazy_add;

                if (rc->lazy_set) *rc->lazy_set += lazy_add;
                else rc->lazy_add += lazy_add;
            }
            lazy_add = T();
        }
    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    static T comb(T a, T b) {
        return min(a, b); // change for min/max/gcd/etc.
    }

    void range_add(ll lq, ll rq, T x) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lazy_add += x;
            push();
            return;
        }
        lc->range_add(lq, rq, x);
        rc->range_add(lq, rq, x);
        pull();
    }

    void range_set(ll lq, ll rq, T x) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lazy_set = x;
            lazy_add = T();
            push();
            return;
        }
        lc->range_set(lq, rq, x);
        rc->range_set(lq, rq, x);
        pull();
    }

    T query(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }

    void point_set(ll idx, T x) {
        push();
        if (lm == rm) {
            val = x;
            return;
        }
        if (idx <= lc->rm) lc->point_set(idx, x);
        else rc->point_set(idx, x);
        pull();
    }
};


int main(){
    _;
    ll n, q; cin >> n >> q;
    vector<ll> v(n);
    forn(i, 0, n) cin >> v[i];

    node<ll> seg(0, n-1, v);

    while (q--) {
        ll a; cin >> a;
        if (a == 0) {
            ll b, d, c; cin >> b >> d >> c;
            seg.range_add(b, d-1, c);
        } else {
            ll b, c; cin >> b >> c;
            cout << seg.query(b, c-1) << ln;
        }
    }
    

    return 0;
}
