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

v64 oc(1000005);
vector<bool> done(1000005);

void solve() {
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i], oc[v[i]]++;
    ll ans = 0;
    forn(i, 0, n) {
        if (oc[v[i]] >= 3 && !done[v[i]]) {
            ans += oc[v[i]]*(oc[v[i]]-1)*(oc[v[i]]-2);
            done[v[i]] = true;
        }
        forn (j, 2, 1001) {
            if(v[i]*j*j > 1000000) break;
            if (oc[v[i]*j] && oc[v[i]*j*j]) {
                ans += oc[v[i]*j] * oc[v[i]*j*j];
            }
        }
    }

    forn(i, 0, n) {
        oc[v[i]] = 0;
        done[v[i]] = false;
    }

    cout << ans << ln;    
}

int main(){
    _;

    ll t; cin >> t;
    while (t--) solve();
    return 0;
}