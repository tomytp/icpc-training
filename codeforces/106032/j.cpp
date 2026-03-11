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

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    v64 v(n);
    map<ll, ll> mp;
    forn(i, 0, n) cin >> v[i], mp[v[i]]++;
    v64 pares;
    for(auto x : mp) {
        if (x.second % 2 == 0) {
            pares.push_back(x.first);
        }
    }
    for (auto x: pares) mp.erase(x);

    ll shifts = 0;
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            shifts++;
        } else {
            ll i; cin >> i;
            i--;
            if (mp.count(v[i])) {
                cout << v[i] << ln;
                continue;
            }

            ll ans = 0;
            auto it = mp.lower_bound(v[i]);
            if (it != mp.end()) {
                ans = (min(shifts, it->first - v[i]));
            } else {
                ll val = mp.lower_bound(0)->first;
                if (sz(mp) == 0) {
                    val = INF;
                }
                ans = min(shifts, (m-v[i]) + val);
            }
            ans--;
            cout << ((v[i]+ans)%m) + 1 << ln;
            
        }
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}