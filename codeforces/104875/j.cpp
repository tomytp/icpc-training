#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


struct node {
    ll val = 0;

    static node comb(const node& a, const node& b) {
        return {max(a.val, b.val)};
    }
};

template<typename T> struct segtree {
    ll n;
    T neutral;
    vector<T> tree;

    segtree<T>(ll _n, T _neutral = T()) {
        n = _n, neutral = _neutral;
        tree.resize(2*n+1, neutral);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), tree.begin() + n);

        for (ll i = n - 1; i > 0; i--) tree[i] = T::comb(tree[2 * i], tree[2 * i + 1]);
    }

    void update(ll i, T v) {
        i += n;
        tree[i] = v;
        while (i > 1) {
            i /= 2;
            tree[i] = T::comb(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(ll i, ll j) {
        T rl = neutral, rr = neutral;
        for (i += n, j+= n; i <=j; i /=2, j /=2) {
            if ((i&1) == 1) rl = T::comb(rl, tree[i++]);
            if ((j&1) == 0) rr = T::comb(tree[j--], rr);
        }
        return T::comb(rl, rr);
    }
};

struct helper{
    ll l, r, idx;

    bool operator < (const helper a) const{
        if(l != a.l) return l < a.l;
        return r > a.r;    
    }
};

int main() {
    _;
    ll n; cin >> n;
    vector<helper> v(n);

    
    vector<ll> pts;
    forn(i, 0, n) {
        ll tam;
        cin >> v[i].l >> tam;
        v[i].l--;
        v[i].r = v[i].l + tam;
        v[i].idx = i;
        pts.push_back(v[i].l);
        pts.push_back(v[i].r);
    }
    sort(pts.begin(), pts.end());
    map<ll, ll> mp;
    forn(i, 0, sz(pts)) {
        mp[pts[i]] = i;
    }
    forn(i, 0, n) {
        v[i].l = mp[v[i].l];
        v[i].r = mp[v[i].r];
    }

    ll segn = sz(pts);
    v64 ans(n);

    sort(v.begin(), v.end());

    vector<node> leafs(segn, {-1});
    segtree<node> seg(segn, {-1});
    seg.set_leaves(leafs);

    v64 aux(segn, -1);

    forn(i,0,n){
        trace(
            cout << v[i].l << " " << v[i].r << ln; 
        )
        ll r = v[i].r;
        ll resp = seg.query(r, segn-1).val + 1;
        ans[v[i].idx] = resp;
        aux[v[i].r] = resp;
        debug(resp);
        seg.update(r, {resp});
        debugv(aux);
    }

    forn(i,0,n) cout << ans[i] << " ";; cout << ln;
    return 0;
} 