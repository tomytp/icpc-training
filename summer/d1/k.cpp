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

// Segment Tree (Range Query + Range Update)
//
// Balanced binary tree for range queries with a customizable combine; supports point updates and range queries.
//
// complexity: O(log N) per op, O(N)

struct lazy {
    ll add = 0;
    optional<ll> set;
    
    void compose(const lazy& o) {
        if (o.set.has_value()) {
            set = o.set;
            add = 0;
        }

        if (o.add != 0) {
            if (set.has_value()) *set += o.add;
            else add += o.add;
        }
    }
};

struct node {
    ll val = 0;
    
    static node comb(const node& a, const node& b) {
        return {min(a.val, b.val)};
    }

    void resolve(const lazy& lz, ll l, ll r) {
        if (lz.set.has_value()) val = *lz.set;
        if (lz.add) val += lz.add;
    }
};

const node neutral = {INF};

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
// Segment Tree (Range Query + Point Update)
//
//supports point updates and range queries.
//
// complexity: O(log N) per op, O(N)

    }

    node query(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return neutral;
        if (lq <= lm && rm <= rq) return val;
        return node::comb(lc->query(lq, rq), rc->query(lq, rq));
    }
};

pair<v64, v64> lis(vector<ll> &v){
	vector<ll> paciencia;
    vector<ll> best_end(sz(v));
    vector<ll> lis_sz(sz(v));
	forn(i, 0, sz(v)){
        if(v[i] == 0){
            if(i == 0){
                lis_sz[i] = 0;
                best_end[i] = -INF;
                continue;
            }
            lis_sz[i] = lis_sz[i-1];
            best_end[i] = best_end[i-1];
            continue;
        }

		auto it = lower_bound(paciencia.begin(), paciencia.end(), v[i]);
		if (it == paciencia.end()) paciencia.push_back(v[i]);
		else *it = v[i];

        lis_sz[i] = sz(paciencia);
        best_end[i] = paciencia.back();
	}
	return {lis_sz, best_end};
}

int solve(){
    ll n; cin >> n;
    if (n == 0) exit(0);
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 v2 = v;
    reverse(v2.begin(), v2.end());
    forn(i, 0, n) v2[i]= -v2[i];

    vector<node> vnode(n+5);
    tree seg(0, n+4, vnode);
    auto [a, b] = lis(v);
    auto [c, d] = lis(v2);

    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    forn(i, 0, n) d[i] = -d[i];

    ll listot = a.back();

    debug(listot);
    forn(i, 0, n) {
        if (v[i] != 0) continue;
        debug(a[i]);
        debug(b[i]);
        debug(c[i]);
        debug(d[i]);
        if (a[i] + c[i] != listot) continue;
        if (d[i] - 1 > b[i]) {
            lazy upt;
            upt.set = 1;
            seg.range_update(b[i] + 1, d[i] - 1, upt);
        }
    }

    ll ans = 0;
    forn(i, 1, n+1) {
        ans += (listot + seg.query(i,i).val) * i;
    }

    cout << ans << ln;
    return 0;
}

int main() {
    _;
    while (true) solve();
}