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

struct piece{
    ll l, r, h, l_comp, r_comp;
};

template<typename T>
struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;

    static constexpr T neutral = {-INF, INF};
    T val = neutral;
    T lazy_add = T();
    optional<T> lazy_set = nullopt;

    node(ll lm_, ll rm_, const vector<T>& v) : lm(lm_), rm(rm_) {
        if(lm == rm) val = v[lm];
        else {
            ll mid = (lm + rm)/2;
            lc = make_unique<node>(lm, mid, v);
            rc = make_unique<node>(mid+1, rm, v);
            pull();
        }
    }

    void push(){
        if(lazy_set.has_value()){
            val = *lazy_set;
            if(lm != rm){
                lc->lazy_set = rc->lazy_set = lazy_set;
                lc->lazy_add = rc->lazy_add = T();
            }
            lazy_set.reset();
        }

    }

    void pull() {
        val = comb(lc->val, rc->val);
    }

    static T comb(T a, T b){
        return {max(a.first, b.first), min(a.second, b.second)};
    }

    void range_add(ll lq, ll rq, T x){
        push();
        if(rq < lm || lq > rm) return;
        if(lq <= lm && rm >=rq) {
            lazy_add += x;
            push();
            return;
        }
        lc->range_add(lq, rq, x);
        rc->range_add(lq, rq, x);
        pull();
    }

    void range_set(ll lq, ll rq, T x){
        push();
        if(rq< lm || lq > rm) return;
        if(lq <= lm && rm <= rq) {
            lazy_set = x;
            lazy_add = T();
            push();
            return;
        }
        lc->range_set(lq, rq, x);
        rc->range_set(lq, rq, x);
        pull();
    }

    T query(ll lq, ll rq){
        push();
        if(rq < lm || lq > rm) return neutral;
        if(lq <= lm && rm <= rq) return val;
        return comb(lc->query(lq, rq), rc->query(lq, rq));
    }

    void point_set(ll idx, T x){
        push();
        if(lm == rm) {
            val = x;
            return;
        }
        if(idx <= lc->rm) lc->point_set(idx, x);
        else rc->point_set(idx, x);
        pull();
    }
};

int main() {
    _; ll n; cin >> n;
    vector<piece> tetris(n);


    set<ll> s;

    forn(i, 0, n){
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if(c == '|'){ 
            tetris[i].l = b;
            tetris[i].r = b;
            tetris[i].h = a;
        }
        if(c == '-'){
            tetris[i].l = b;
            tetris[i].r = a+b-1;
            tetris[i].h = 1;
        }

        s.insert(tetris[i].l);
        s.insert(tetris[i].r);
    }

    ll best = 0;
    map<ll, ll> trad;
    ll cnt = 0;
    ll last = -1;
    for(ll x : s){
        if(x - last == 1) trad[x] = cnt++;
        else{
            cnt++;
            trad[x] = cnt++;
        }
        last = x;
    }

    forn(i,0,n){
        debug(tetris[i].l);
        debug(tetris[i].r);

        tetris[i].l_comp = trad[tetris[i].l];
        tetris[i].r_comp = trad[tetris[i].r];
        best = max(best, tetris[i].l_comp);
        best = max(best, tetris[i].r_comp);
    }

    best += 10;
    vector<p64> v(best, {0,0});

    string ans;
    node seg(0, best-1, v);

    forn(i, 0, n){
        debug(tetris[i].r_comp);
        debug(tetris[i].l_comp);
        if(tetris[i].r_comp == tetris[i].l_comp){
            ll l = tetris[i].r_comp;
            ans.push_back('S');
            p64 aux = seg.query(l, l);
            seg.point_set(l, {aux.first + tetris[i].h, aux.second + tetris[i].h});
        }
        else{
            ll l = tetris[i].l_comp, r = tetris[i].r_comp;;
            p64 aux = seg.query(l, r);
            if(aux.first != aux.second){
                ans.push_back('U');
                continue;
            }
            ans.push_back('S');
            seg.range_set(l, r, {(aux.first)+1, (aux.first)+1});
        }
    }

    cout << ans << ln;

    return 0;
}