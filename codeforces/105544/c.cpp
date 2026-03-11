#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

template<typename T>
struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;

    static constexpr T neutral = T();
    T ones = neutral;
    T zeros = neutral;
    bool fliped = false;

    node(ll lm_, ll rm_, const vector<T>& v) : lm(lm_), rm(rm_) {
        if (lm == rm) {
            if (v[lm] == 1) ones++;
            if (v[lm] == 0) zeros++;
        }
        else {
            ll mid = (lm + rm) / 2;
            lc = make_unique<node>(lm, mid, v);
            rc = make_unique<node>(mid + 1, rm, v);
            pull();
        }
    }

    void push() {
        if (fliped) {
            swap(ones, zeros);
            if (lm != rm) {
                lc->fliped = !lc->fliped;
                rc->fliped = !rc->fliped;
            }
            fliped = false;
        }
    }

    void pull() {
        ones = comb(lc->ones, rc->ones);
        zeros = comb(lc->zeros, rc->zeros);
    }

    static T comb(T a, T b) {
        return a + b; // pensa
    }

    void range_flip(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            fliped = !fliped;
            push();
            return;
        }
        lc->range_flip(lq, rq);
        rc->range_flip(lq, rq);
        pull();
    }

    T query(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return ones;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }
};

int main() {
    _;
    ll n, m; cin >> n >> m;
    ll tot = 0;
    v64 state(n);
    forn(i, 0, n) {
        ll aux;
        cin >> state[i] >> aux;
        tot += aux; 
    }

    node seg(0, n-1, state);

    forn(i, 0, m) {
        char c; cin >> c;
        if (c == 'W') {
            ll l, r; cin >> l >> r;
            seg.range_flip(l, r);
        } else {
            ll val; cin >> val;
            val *= seg.query(0, n-1);
            tot += val;
        }
    }

    cout << tot << ln;

    
    return 0;
}