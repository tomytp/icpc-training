#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void) 0
    #define debug(x) cout << __LINE__  << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    ll val = 0;

    static node comb(const node& a, const node& b) {
        return {a.val ^ b.val};
    }
};

const node neutral = {0};

struct tree {
    ll lm, rm;
    unique_ptr<tree> lc, rc;

    node val;

    tree (ll l_, ll r_, const vector<node>& v) : lm(l_), rm(r_) {
        if (lm == rm) {
            val = v[lm] ;
        } else {
            ll m = (lm + rm) / 2;
            lc = make_unique<tree>(lm, m , v);
            rc = make_unique<tree>(m+1, rm, v);
            pull();
        }
    }

    void pull() {
        val = node::comb(lc->val, rc->val);
    }

    void point_set(ll idx, node x) {
        if (lm == rm) {
            val = x;
            return;
        }
        if (idx <= lc->rm) lc->point_set(idx, x);
        else rc->point_set(idx, x);
        pull();
    }

    node query(ll lq, ll rq){
        if(rq < lm || lq > rm) return neutral;
        if(lq <= lm && rm <= rq) return val;
        return node::comb(lc->query(lq,rq), rc->query(lq,rq));
    };
};


int main() {
    _;
    ll n, q; cin >> n >> q;

    vector<node> vec(n);
    forn(i,0,n) {
        cin >> vec[i].val;
    }

    tree seg(0,n-1, vec);

    while(q--){
        char c; cin >> c;
        if(c == 'P'){
            ll l, r;
            cin >> l >> r;
            l--; r--;
            ll resp = seg.query(l, r).val;
            if(resp == 0){
                cout << "JUAN" << ln;
            }else{
                cout << "FRANK" << ln;
            }
        }else{
            ll k, x;
            cin >> k >> x;
            k--;
            ll curr = seg.query(k,k).val;
            seg.point_set(k, {curr+x});
        }
    }
    return 0;
}