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


ll ask(ll a, ll b) {
    ll ans = 0;
    while (true) {
        if (a == 0) return ans % 3;
        if (a == b) return (ans + 2) % 3;
        if (a < b && b/a > 5) {
            ll count = (b-a) / (a*2);
            b = b-(count*a)*2;
        }
        ans++;
        ll na = b;
        ll nb = abs(a-b);
        a = na;
        b = nb;
    }
    return 0;
}

void solve() {
    ll n; cin >> n;
    v64 a(n), b(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];

    set<ll> st;
    forn(i, 0, n) {
        if (a[i] == 0 && b[i] == 0) continue;
        st.insert(ask(a[i], b[i]));
    }

    if (st.size() > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}