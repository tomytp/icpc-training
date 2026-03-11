#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    ll lm, rm;
    ll mn;
    unique_ptr<node> lc, rc;

    node(ll l, ll r, const vector<ll>& a) : lm(l), rm(r) {
        if (lm == rm) { 
            mn = a[lm];
             return; 
        }

        ll m = (lm + rm) >> 1;
        lc = make_unique<node>(lm, m, a);
        rc = make_unique<node>(m+1, rm, a);
        pull();
    }

    static ll comb(ll a, ll b) {
        return min(a, b);
    }

    void pull() {
        mn = comb(lc->mn, rc->mn);
    }

    void upd(ll lq, ll rq, ll x, vector<pair<node*,ll>>& log) {
        if (lq > rm || rq < lm) return;
        if (lq <= lm && rq >= rm) {
            if (mn < x) {
                log.emplace_back(this, mn);
                mn = x;
            }
            return;
        }

        lc->upd(lq, rq, x, log);
        rc->upd(lq, rq, x, log);
        
        ll nxt = comb(lc->mn, rc->mn);
        
        if (mn < nxt) {
            log.emplace_back(this, mn);
            mn = nxt;
        }
    }

    ll get(ll lq, ll rq) const {
        if (lq > rm || rq < lm) return INF;
        if (lq <= lm && rq >= rm)  return mn;
        ll res = min(lc->get(lq, rq), rc->get(lq, rq));
        return max(res, mn);
    }
};

struct segtree {
    unique_ptr<node> root;
    vector<pair<node*,ll>> log;

    segtree(const v64& a) {
        root = make_unique<node>(0, (ll)a.size()-1, a);
    }

    void upd(ll l, ll r, ll x){
        root->upd(l, r, x, log);
    }

    ll get(ll l, ll r){
        return root->get(l, r);
    }

    ll version() const {
        return (ll)log.size();
    }

    void rollback(ll ver){
        while ((ll)log.size() > ver){
            auto [p, old] = log.back();
            log.pop_back();
            p->mn = old;
        }
    }
};

ll get_t(char c) {
    if (c == '+') return 0;
    if (c == '-') return 1;
    else return 2;
}

struct query {
    ll t, val, l, r, tin, tout;

    query(){}
    query(ll t_, ll val_, ll l_, ll r_, ll tin_, ll tout_) {
        t = t_;
        val = val_;
        l = l_;
        r = r_;
        tin = tin_;
        tout = tout_;
    }

    void print() {
        if (t == 0) {
            cout << "ADD: " << tin << " " << tout << " " << val << << " " << l << " " << r << ln; 
        }
    }
};

ll mxx = 0;

vector<query> read_input() {
    ll n; cin >> n;
    map<ll, ll> comp;
    vector<v64> queries(n);
    ll id = 1;
    map<ll, query> vq; 
    vector<query> perguntas;
    forn(i, 0, n) {
        char c; cin >> c;
        if (c == '+') {
            ll a, b, d; cin >> a >> b >> d;
            comp[a];
            comp[b];
            vq[id] = query(0ll, d, a, b, i, -1);
            id++;
        } else if (c == '-') {
            ll k; cin >> k;
            vq[k].tout = i-1;
        } else {
            ll a, b; cin >> a >> b;
            comp[a];
            comp[b];
            perguntas.push_back(query(1ll, -1ll, a, b, i, i));
        }
    }

    ll i = -1, last = -5;
    for(auto& [k, v] : comp) {
        ll aux = v;
        if (v - 1 == last) v = i++;
        else i++, v = i++;
        last = aux;
    }

    mxx = prev(comp.end())->second;

    forn(j, 0, (ll)perguntas.size()) {
        perguntas[j].l = comp[perguntas[j].l];
        perguntas[j].r = comp[perguntas[j].r];
    }

    for (auto& [k, v] : vq) {
        v.l = comp[v.l];
        if (v.r == -1) {
            v.r = mxx;
        } else {
            v.r = comp[v.r];
        }
        perguntas.push_back(v);
    }

    // forn(j, 0, perguntas.size()) {
    //     cout << perguntas[j].t << " " << perguntas[j].val << "\n";
    // }

    return perguntas;
}


struct prob {
    ll lm, rm;
    unique_ptr<prob> lc, rc;
    vector<query> queries;
 
    prob(ll lm_, ll rm_) : lm(lm_), rm(rm_) {
        if (lm != rm) {
            ll mid = (lm + rm) / 2;
            lc = make_unique<prob>(lm, mid);
            rc = make_unique<prob>(mid + 1, rm);
        }
    }
 
    void add_query(query& q, ll lq, ll rq)  {
        if (lq <= lm && rq >= rm) {
            queries.push_back(q);
        } else if (lq > rm || rq < lm) {
            return;
        } else {
            lc->add_query(q, lq, rq);
            rc->add_query(q, lq, rq);
        }
    }
 
    void dfs(segtree& seg) {
        ll version = seg.version();
        for(auto& q : queries) {
            if (q.t == 0) seg.upd(q.l, q.r, q.val);
        }
 
        for (auto& q : queries) if (q.t == 1) {
            forn(i, 0, seg.root->rm + 1) cout << seg.get(i, i) << " \n"[i == seg.root->rm];
            cout << seg.get(q.l, q.r) << ln;
        }
 
        if (lm != rm) {
            lc->dfs(seg);
            rc->dfs(seg);    
        }
        
        seg.rollback(version);
    }
};
 

int main() {
    _;
    auto q = read_input();
    ll n = q.size();
    
    prob p(0, n);
    forn(i, 0, n) {
        p.add_query(q[i], q[i].tin, q[i].tout);
    }

    v64 vec(mxx+5, 0);
    segtree seg(vec);

    p.dfs(seg);

    return 0;
}