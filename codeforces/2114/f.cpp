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

const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const ll MAXX = 1'000'000;

ll factor[MAXX + 1];
void sieve() {
    forn(i,0,MAXX+1) factor[i] = i;
    for (ll i = 2; i * 1LL * i <= MAXX; ++i)
        if (factor[i] == i)
            for (ll j = i * i; j <= MAXX; j += i)
                if (factor[j] == j) factor[j] = i;
}

inline void factor_list(ll n, v64& out) {
    while (n > 1) {
        out.push_back(factor[n]);
        n /= factor[n];
    }
}

ll ans(vector<ll> f, ll k){
    if (!f.size()) return 0;
    if (*max_element(f.begin(),f.end()) > k) return -1;

    ll prodd = 1;
    bool fits = true;
    for(ll v: f){
        if ((double)prodd * v > 1e18) fits = false;
        prodd *= v;
        if (prodd > k) fits = false;
    }
    if (fits) return 1;

    sort(f.rbegin(), f.rend());
    const ll n = f.size();

    double sumlog = 0, logk = log(k);
    for(ll v: f) sumlog += log(v);
    ll lo = (logk==0)? n : ceil(sumlog / logk - 1e-12);

    vector<ll> bucket(n,1);
    function<bool(ll,ll,ll)> dfs = [&](ll idx,ll used,ll limit)->bool{
        if (idx == n) return true;
        ll val = f[idx];
        unordered_set<ll> seen;
        for(ll i=0;i<used;++i){
            if (bucket[i]*val<=k && !seen.count(bucket[i])){
                seen.insert(bucket[i]);
                bucket[i]*=val;
                if (dfs(idx+1,used,limit)) return true;
                bucket[i]/=val;
            }
        }
        if (used < limit){
            bucket[used] = val;
            if (dfs(idx+1,used+1,limit)) return true;
            bucket[used] = 1;
        }
        return false;
    };

    for(ll limit=lo; limit<=n; ++limit){
        if (dfs(0,0,limit)) return limit;
    }
    return n;
}


void solve() {
    ll x, y, k; cin >> x >> y >> k;
    if (x == y) { cout << 0 << ln; return; }

    ll g = gcd(x, y);
    ll rem = x / g, add = y / g;

    v64 to_remove, to_add;
    factor_list(rem, to_remove);
    factor_list(add, to_add);

    if ((rem > 1 && *max_element(to_remove.begin(), to_remove.end()) > k) ||
        (add > 1 && *max_element(to_add.begin(), to_add.end()) > k)) {
        cout << -1 << ln;
        return;
    }

    ll a = ans(to_remove, k);
    ll b = ans(to_add, k);
    if (a == -1 || b == -1) cout << -1 << ln;
    else cout << a + b << ln;
}
int main() { _;
    sieve();
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
