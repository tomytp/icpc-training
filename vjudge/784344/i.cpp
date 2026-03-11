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
ll n;
vector<string> a, b;
vector<p64> pairs;
ll tot = 0;

ll lcp(ll ia, ll ib, ll i) {
    ll sum = 0; 
    if (ia >= sz(a) || ib >= sz(b)) return 0;
    for (; i < sz(a[ia]) && i < sz(b[ib]); i++) {
        if (a[ia][i] == b[ib][i]) sum++;
        else return sum;
    }
    return sum;
}

pair<v64, v64> solve(ll ia, ll fa, ll ib, ll fb, ll i) {
    ll sa = fa - ia;
    ll sb = fb - ib;
    debug(ia);
    debug(fa);
    debug(ib);
    debug(fb);
    debug(i);
    if (sa == 0) {
        v64 ans;
        forn(j, ib, fb) ans.push_back(j);
        return {{}, ans};
    }
    if (sb == 0) {
        v64 ans;
        forn(j, ia, fa) ans.push_back(j);
        return {ans, {}};
    }
    if (sa == 1 && sb == 1) {
        tot += lcp(ia, ib, i);
        pairs.emplace_back(ia, ib);
        return {};
    }

    if (sa == 1) {
        auto idx = upper_bound(b.begin() + ib, b.begin() + fb, a[ia]) - (b.begin());
        ll curr = lcp(ia, idx, i);
        if (idx >= fb) curr = -1;
        if (idx > ib) {
            ll nx = lcp(ia, idx-1, i);
            if (nx > curr) idx = idx-1, curr = nx;
        } 
        tot += curr;
        pairs.emplace_back(ia, idx);
        v64 ans; ans.reserve(fb-ib);
        forn(j, ib, fb) if (j != idx) ans.push_back(j);
        return {{}, ans};
    }

    if (sb == 1) {
        auto idx = upper_bound(a.begin() + ia, a.begin() + fa, b[ib]) - (a.begin());
        ll curr = lcp(idx, ib, i);
        if (idx >= fa) curr = -1;
        if (idx > ia) {
            ll nx = lcp(idx-1, ib, i);
            if (nx > curr) idx = idx-1, curr = nx;
        }
        tot += curr;
        pairs.emplace_back(idx, ib);
        v64 ans; ans.reserve(fa-ia);
        debug(idx);
        forn(j, ia, fa) if(j != idx) ans.push_back(j);
        return {ans, {}};
    }

    pair<v64, v64> rs;
    ll la = 0, lb = 0;
    ll pa = 0, pb = 0;
    forn(l, 0, 26) {
        char c = 'a' + l;
        while (ia+pa < fa && a[ia+pa][i] == c) pa++;
        while (ib+pb < fb && b[ib+pb][i] == c) pb++;
        tot += min(pa-la, pb-lb);
        auto resto = solve(ia+la, ia+pa, ib+lb, ib+pb, i+1);
        debug(c);
        debug(i);
        debugv(resto.first);
        debugv(resto.second);
        if (sz(resto.first) > sz(rs.first)) swap(resto.first, rs.first);
        if (sz(resto.second) > sz(rs.second)) swap(resto.second, rs.second);
        for (auto x : resto.first) rs.first.push_back(x);
        for (auto x : resto.second) rs.second.push_back(x);
        
        la = pa;
        lb = pb;
        if (ia + pa == fa && ib + pb == fb) break;
    }
    
    ll j = 0;
    ll mx = min(sz(rs.first), sz(rs.second));
    for (; j < mx; j++) {
        pairs.emplace_back(rs.first[j], rs.second[j]);
    }
    v64 peixea, peixeb;
    while (j < sz(rs.first)) peixea.push_back(rs.first[j++]);
    while (j < sz(rs.second)) peixeb.push_back(rs.second[j++]);
    return {peixea, peixeb};
};

int main(){
    _;
    cin >> n;
    a.resize(n);
    b.resize(n);
    vector<pair<string, ll>> a_aux(n);
    vector<pair<string, ll>> b_aux(n);

    forn(i, 0, n){
        cin >> a_aux[i].first;
        a_aux[i].second = i;
    }

    forn(i, 0, n){
        cin >> b_aux[i].first;
        b_aux[i].second = i;
    }

    sort(a_aux.begin(), a_aux.end());
    sort(b_aux.begin(), b_aux.end());


    v64 trada(n);
    v64 tradb(n);

    forn(i,0,n){
        trada[i] = a_aux[i].second;
        tradb[i] = b_aux[i].second;
 
        a[i] = a_aux[i].first;
        b[i] = b_aux[i].first;
    }

    auto l = solve(0, n, 0, n, 0);

    cout << tot << ln;
    // for (auto p : pairs) {
    //     cout << trada[p.first]+1 << " " << tradb[p.second]+1 << ln;
    // }
    
    ll sum = 0;
    for (auto p : pairs) {
        sum += lcp(p.first, p.second, 0);
    }
    assert(sum == tot);
    return 0;
} 