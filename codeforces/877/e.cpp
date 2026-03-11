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

    static constexpr T neutral = T();
    ll val = 0;
    bool lazy = false;

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
        if (lazy) {
            val = (rm-lm+1) - val;
            if (lm != rm) {
                lc->lazy = !lc->lazy;
                rc->lazy = !rc->lazy; 
            }
            lazy = false;
        }
    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    static T comb(T a, T b) {
        return a + b;
    }

    void range_flip(ll lq, ll rq) {
        push();
        if (rq < lm || lq > rm) return;
        if (lq <= lm && rm <= rq) {
            lazy = true; 
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
        if (lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }
};


int main(){
    _;
    ll n; cin >> n;
    vector<v64> g(n);
    forn(i, 1, n) {
        ll a; cin >> a;
        a--;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    v64 on(n);
    forn(i, 0, n) cin >> on[i];

    v64 to_seg;
    vector<p64> idx(n);
    function<void (ll ,ll)> dfs = [&](ll u, ll p) {
        idx[u].first = to_seg.size();
        to_seg.push_back(on[u]);

        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(v, u);
        }

        idx[u].second = to_seg.size();
        to_seg.push_back(on[u]);
    };
    dfs(0, -1);

    node<ll> seg(0, (2*n) -1, to_seg);
    ll q; cin >> q;
    forn(i, 0, q) {
        string c; cin >> c;
        ll x; cin >> x; x--;
        if (c[0] == 'g') {
            cout << seg.query(idx[x].first, idx[x].second) / 2 << ln;
        } else {
            seg.range_flip(idx[x].first, idx[x].second);
        }
    }
    return 0;
}
