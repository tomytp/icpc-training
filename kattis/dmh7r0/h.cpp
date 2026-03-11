#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    ll nmins = 0, mini = INF, smins = 0;
    node operator*(const node &o) const { 
        if (mini == o.mini) return {nmins + o.nmins, mini, smins + o.smins};
        if (mini < o.mini) return {nmins, mini, smins};
        return {o.nmins, o.mini, o.smins};
    }
};

struct update {
    ll add = 0;
    node operator()(const node &n) const {
        return {n.nmins, n.mini + add, n.smins};
    }
    update operator+(const update &o) {
        update res = *this;
        res.add += o.add;
        return res;
    } 
};


template<typename T, typename U> struct segtree {
  ll s, h;

  T id;
  vector<T> val;

  U noop;
  vector<bool> dirty;
  vector<U> prop;

  explicit segtree(ll ts, T tid = T(), U tnoop = U()) {
    id = tid, noop = tnoop;
    for (s = 1, h = 1; s < ts; ) s *= 2, h++;

    val.assign(2*s, id);
    dirty.assign(2*s, false);
    prop.assign(2*s, noop);
  }

  void set_leaves(vector<T> &lvs) {
    copy(lvs.begin(), lvs.end(), val.begin() + s);

    for (ll i = s - 1; i > 0; i--) val[i] = val[2 * i] * val[2 * i + 1];
    dirty.assign(2*s, false);
    prop.assign(2*s, noop);
  }

  void apply(ll i, U &upd) {
    val[i] = upd(val[i]);
    if(i < s) {
      prop[i] = prop[i] + upd;
      dirty[i] = true;
    }
  }

  void pull(ll i) {
    for (ll l = i/2; l; l /= 2) {
      T comb = val[2*l] * val[2*l+1];
      val[l] = prop[l](comb);
    }
  }

  void push(ll i) {
    for (ll h = h; h > 0; h--) {
      ll l = i >> h;

      if (dirty[l]) {
        apply(2*l, prop[l]);
        apply(2*l+1, prop[l]);

        prop[l] = noop;
        dirty[l] = false;
      }
    }
  }

  void update(ll i, ll j, U upd) {
    i += s, j += s;
    push(i), push(j);

    for (ll l = i, r = j; l <= r; l /= 2, r /= 2) {
      if((l&1) == 1) apply(l++, upd);
      if((r&1) == 0) apply(r--, upd);
    }

    pull(i), pull(j);
  }

  T query(ll i, ll j){
    i += s, j += s;
    push(i), push(j);

    T rl = id, rr = id;
    for(; i <= j; i /= 2, j /= 2){
      if((i&1) == 1) rl = rl * val[i++];
      if((j&1) == 0) rr = val[j--] * rr;
    }
    return rl * rr;
  }
};

int main() {
    _;
    ll q, w; cin >> q >> w;
    vector<p64> queries(q);
    forn(i, 0, q) cin >> queries[i].first >> queries[i].second;
    vector<p64> interval(q);
    set<ll> pts;
    pts.insert(0);
    pts.insert(1);
    pts.insert(-1);
    pts.insert(-INF);
    pts.insert(INF);
    pts.insert(w-1);
    pts.insert(w);
    pts.insert(w+1);

    forn(i, 0, q) {
        interval[i].first = queries[i].first - queries[i].second;
        interval[i].second = queries[i].first + queries[i].second;
        pts.insert(interval[i].first-1);
        pts.insert(interval[i].first);
        pts.insert(interval[i].first+1);
        pts.insert(interval[i].second-1);
        pts.insert(interval[i].second);
        pts.insert(interval[i].second+1);
    }
    vector<node> intval(sz(pts));
    map<ll, ll> to_idx;
    ll curr = -INF;
    ll idx = 0;
    for (auto x : pts) {
        intval[idx].smins = x - curr;
        intval[idx].mini = 0;
        intval[idx].nmins = 1;
        to_idx[curr] = idx;
        idx++;
        curr = x;
    }

    segtree<node, update> seg(sz(intval));
    seg.set_leaves(intval);

    set<p64> open;
    forn(i, 0, q) {
        if (open.count(queries[i])) {
            open.erase(queries[i]);
            update u = {-1};
            seg.update(to_idx[interval[i].first], to_idx[interval[i].second]-1, u);
        } else {
            open.insert(queries[i]);
            update u = {+1};
            seg.update(to_idx[interval[i].first], to_idx[interval[i].second]-1, u);
        }
        auto a = seg.query(to_idx[0], to_idx[w]-1);
        ll rev = 0;
        if (a.mini == 0) {
            rev = a.smins;
        }
        cout << fixed << setprecision(20) << (long double)(w - rev) * sqrtl(2) << ln;
    }
    
    return 0;
}