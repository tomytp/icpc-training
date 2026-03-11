#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;

    static constexpr p64 neutral = p64();
    p64 val = neutral;
    ll lazy_add = 0;

    node(ll lm_, ll rm_, const vector<p64>& v) : lm(lm_), rm(rm_) {
        if (lm == rm) val = v[lm];
        else {
            ll mid = (lm + rm) / 2;
            lc = make_unique<node>(lm, mid, v);
            rc = make_unique<node>(mid + 1, rm, v);
            pull();
        }
    }

    void push() {
        if (lazy_add != 0) {
            val.first += lazy_add;
            if (lm != rm) {
                lc->lazy_add += lazy_add;
                rc->lazy_add += lazy_add;
            }
            lazy_add = 0;
        }
    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    static p64 comb(p64 a, p64 b) {
        return max(a, b);
    }

    void range_add(ll lq, ll rq, ll x) {
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

    p64 query(ll lq, ll rq) {
        push();
        if(rq < lm || lq > rm) return neutral;
        if(lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }
};


int main() {
    _;
    ll n, k; cin >> n >> k;
    v64 parent(n, -1);
    vector<v64> g(n);
    forn(i, 1, n) {
        ll x; cin >> x; x--;
        g[x].push_back(i);
        parent[i] = x;
    }

    vector<p64> idx(n);
    vector<p64> to_seg; to_seg.reserve(2*n);
    function<void (ll, ll)> dfs = [&](ll u, ll h) {
        idx[u].first = to_seg.size();
        to_seg.emplace_back(h, u);
        
        for (auto v : g[u]) {
            dfs(v, h + 1);
        }
        
        idx[u].second = to_seg.size();
        to_seg.emplace_back(h, u);
    };
    dfs(0, 1);

    node seg(0, (2*n) - 1, to_seg);
    vector<bool> valid(n, true);
    ll ans = 0;

    forn(i, 0, k) {
        p64 best = seg.query(0, 2*n-1);
        if (valid[best.second] == false) break;

        ans += best.first;
        ll u = best.second;
        while (u != -1 && valid[u]) {
            auto id = idx[u];
            seg.range_add(id.first, id.second, -1);
            valid[u] = false;
            u = parent[u];
        }
    }

    cout << ans << ln;
        
    return 0;
}