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

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    _;
    ll n; cin >> n;
    v64 cnt(5);
    vector<ll> limits(n);
    forn(i, 0, 5) cin >> cnt[i];
    forn(i, 0, n) {
        bitset<5> bt;
        ll m; cin >> m;
        forn(i, 0, m) {
            ll aux; cin >> aux;
            bt[aux - 1] = true;
        }
        limits[i] = bt.to_ullong();
    }

    vector<v64> g(n);
    forn(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    ll p; cin >> p;
    vector<p64> vp(p);
    forn(i, 0, p) cin >> vp[i].first >> vp[i].second;



    return 0;
}