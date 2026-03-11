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

struct lazy {
    ll add = 0;
    
    void compose(const lazy& o) {
        if (o.add != 0) {
            add += o.add;
        }
    }
};

struct node {
    ll sum, maxi = 0;
    
    static node comb(const node& a, const node& b) {
        return {a.sum + b.sum, max(a.maxi, b.maxi)};
    }

    void resolve(const lazy& lz, ll l, ll r) {
        sum += lz.add * (r-l + 1);
        maxi = maxi + lz.add;
    }
};

const node neutral = {0, -INF};

struct tree {
    ll lm, rm;
    unique_ptr<tree> lc, rc;
    
    node val;
    lazy lz;

    tree(ll l_, ll r_, const vector<node>& v) : lm(l_), rm(r_) {
        if (lm == rm) val = v[lm];
        else {
            ll m = (lm + rm) / 2;
            lc = make_unique<tree>(lm, m, v);
            rc = make_unique<tree>(m + 1, rm, v);
            pull();
        }
    }

    void pull() {
        val = node::comb(lc->val, rc->val);
    }

    void push() {
        val.resolve(lz, lm, rm);
        if (lm != rm) {
            lc->lz.compose(lz);
            rc->lz.compose(lz);
        }
        lz = {};
    }

    void range_update(ll lq, ll rq, lazy x) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lz.compose(x);
            push();
            return;
        }
        lc->range_update(lq, rq, x);
        rc->range_update(lq, rq, x);
        pull();
    }

    node query(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return node::comb(lc->query(lq, rq), rc->query(lq, rq));
    }

    ll find() {
        push();
        if (lm == rm) return lm;
        ll lmax = lc->val.maxi + lc->lz.add;
        if (lmax >= 0) return lc->find();
        ll rmax = rc->val.maxi + rc->lz.add;
        if (rmax >= 0) return rc->find();
        return -1;
    }
};

int main(){
    _;
    ll ac, dr; cin >> ac >> dr;
    ll n; cin >> n;
    v64 a(n), d(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> d[i];
    ll q; cin >> q;
    vector<node> v(n+2);
    forn(i, 0, n+2) {
        v[i] = {i, i};
    }
    tree seg(0, n+1, v);
    forn(i, 0, n) {
        ll p = max(a[i] - ac, 0ll) + max(d[i] - dr, 0ll);
        seg.range_update(p, n-1, {-1});
    }

    while (q--) {
        ll i, na, nd; cin >> i >> na >> nd;
        i--;
        ll p = max(a[i] - ac, 0ll) + max(d[i] - dr, 0ll);
        seg.range_update(p, n+1, {1});
        a[i] = na;
        d[i] = nd;
        p = max(a[i] - ac, 0ll) + max(d[i] - dr, 0ll);
        seg.range_update(p, n+1, {-1});

        cout << seg.find() << ln;
        // forn(j, 0, n+2) cout << seg.query(j, j).maxi << " \n"[j==n+1];
    }
    return 0;
}