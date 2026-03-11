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

ll ans(ll c1, ll c2, ll c3, ll dist) {
    if (c3 >= 2 * min(c1, c2)) {
        return dist * min(c1,c2);
    }
    ll resp = 0;
    if (dist%2 == 1) {
        resp += min(c1,c2);
    }
    resp += (dist/2) * c3;
    return resp;
}

void solve() {
    ll n; cin >> n;
    ll a, b; cin >> a >> b;
    ll t1, t2, t3, t4, t5, t6;
    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;

    ll dist1 = (max(a,b) - min(a, b));
    ll dist2 = n - dist1;

    if (a > b) swap(dist1, dist2);

    ll resp = min(ans(t1, t4, t5, dist1), ans(t2, t3, t6, dist2));

    if (dist1&1) {
        resp =  min(resp, ans(t1, t4, t5, dist1+1) + t2);
        resp =  min(resp, ans(t1, t4, t5, dist1+1) + t3);
    }
    if (dist2&1) {
        resp = min(resp, ans(t2, t3, t6, dist2+1) + t1);
        resp = min(resp, ans(t2, t3, t6, dist2+1) + t4);
    }

    cout << resp << ln;
} 

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}