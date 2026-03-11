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

vector<string> th = {"", "0", "00", "000"};
vector<string> hu = {"", "1", "11", "111", "12", "2", "21", "211", "2111", "10"};
vector<string> te = {"", "4", "44", "444", "43", "3", "34", "344", "3444", "41"};
vector<string> un = {"", "6", "66", "666", "65", "5", "56", "566", "5666", "64"};


string to_roman(ll n){
    string uni = un[n%10];
    n/=10;
    string ten = te[n%10];
    n/=10;
    string hun = hu[n%10];
    n/=10;
    string tho = th[n%10];

    return tho + hun + ten + uni;
}

pair<ll,p64> junta(pair<ll,p64> p, pair<ll,p64> q){
    if(p.first > q.first) return p;
    if(p.first < q.first) return q;

    return {p.first, {p.second.first, q.second.first}};
}

struct node {
    vector<vector<pair<ll,p64>>> mp;
    v64 mini;
    
    node() : mp(7, vector<pair<ll, p64>>(3, {0, {-1, -1}})), mini(7) {}
    // 0 pref
    // 1 soma
    // 2 suf
    // valor 
    static node comb(const node& a, const node& b) {
        node nw;
        
        forn(i, 0, 7) {
            nw.mini[i] = max(a.mini[i], b.mini[i]);
            nw.mp[i][0] = junta(a.mp[i][0], b.mp[i][0]);
            nw.mp[i][1].first = a.mp[i][1].first + b.mp[i][1].first;
            nw.mp[i][2] = junta(a.mp[i][2], b.mp[i][2]);
        }
        return nw;
    }  
};

template<typename T> struct segtree {
  ll n;
  T neutral;
  vector<T> tree;

  segtree (ll n_, T _neutral = T()) {
    n = n_, neutral = _neutral;
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

node roman(ll n) {
    string rom = to_roman(n);
    node nw;
    
    ll p1 = 0;
    ll p2 = 0;    
    ll curr = 0;
    while(p2 < sz(rom)){
        if(rom[p1] == rom[p2]){
            p2++;
            continue;
        }
        curr = max(curr, p2-p1);
        nw.mini[rom[p1]-'0'] = max(curr, nw.mini[rom[p1]-'0']);
        p1 = p2;    
    }

    ll cnt = 1;
    forn(i, 1, sz(rom)) if (rom[i] == rom[i-1]) cnt++;
    if (cnt == sz(rom)) {
        nw.mp[rom[0] - '0'][1] = {sz(rom), {-1,-1}};
        return nw;
    }
    cnt = 1;
    forn(i, 1, sz(rom)) {
        if (rom[i] == rom[i-1]) cnt++;
        else break;
    }
    nw.mp[rom[0] - '0'][0] = {cnt, {n,-1}};

    cnt = 1;
    for(ll i = sz(rom) - 2; i >= 0; i--) {
        if (rom[i] == rom[i+1]) cnt++;
        else break;
    }
    nw.mp[rom[sz(rom)-1] - '0'][2] = {cnt, {n,-1}};
    return nw;
}

int main(){
    _;
    
    segtree<node> seg(4000);
    vector<node> leaves(4000); 
    forn(i, 1, 4000) {
        leaves[i] = roman(i);
    }
    seg.set_leaves(leaves);

    ll t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        forn(i, l ,r+1) debug(to_roman(i));
        auto q = seg.query(l, r);
        ll ans = 0;
        forn(i, 0, 7) {
            ll curr =  q.mp[i][0].first + q.mp[i][2].first + q.mp[i][1].first;
            debug(i);
            debug(curr);
            if( q.mp[i][0].second.second == -1 &&
                q.mp[i][2].second.second == -1 && 
                q.mp[i][0].second.first  == q.mp[i][2].second.first &&
                q.mp[i][0].second.first != -1
            ){ curr--;}
            curr = max(curr, q.mini[i]);
            ans = max(ans,curr);
        }
        cout << ans << ln;
    }
    return 0;
}