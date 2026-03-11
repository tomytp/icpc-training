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

struct node {
    ll chips = 0;
    ll mult = -1;
    
    static node comb(const node& a, const node& b) {
        node nn;

        trace(
            cout << "("<<  a.chips << " :" << a.mult <<" ), (" << b.chips << " :" << b.mult << " )" << ln;
        );

        if(a.mult == -1) nn = b;
        else if(b.mult == -1) nn = a;
        else{
            nn.chips = a.chips*a.mult + b.chips;
            nn.mult = b.mult;
        }

        trace(
            cout << "("<<  nn.chips << " :" << nn.mult <<" )" << ln;
            cout << ln;
        );


        return nn; 
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
    for(i += n, j += n; i <= j; i /= 2, j /= 2){
      if((i&1) == 1) rl = T::comb(rl, tree[i++]);
      if((j&1) == 0) rr = T::comb(tree[j--], rr);
    }
    return T::comb(rl, rr);
  }
};

int main(){
    _;
    ll n; cin >> n;
    v64 a(n), b(n, 1);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n-1) cin >> b[i];

    vector<node> leaves(n);
    forn(i, 0, n){
        leaves[i].chips = a[i];
        leaves[i].mult = b[i];
    }

    node neutral;
    segtree seg(n, neutral);
    seg.set_leaves(leaves);

    ll q; cin >> q;
    forn(i, 0, q){
        ll l, r; cin >> l >> r;
        l--; r--;
        node query = seg.query(l, r);
        cout << query.chips << ln;
    }

    trace(


    );

    return 0;
}