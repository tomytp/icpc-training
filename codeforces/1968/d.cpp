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
    ll n, k, b, s; cin >> n >> k >> b >> s;
    v64 p(n), a(n);
    forn(i, 0, n) cin >> p[i], p[i]--;
    forn(i, 0, n) cin >> a[i];
    b--, s--;

    v64 visa(n), visb(n);
    v64 ia(n), ib(n);
    ll lena, vala, offa;
    ll lenb, valb, offb;
    while(true) {
        if (ia[p[b]]) {
            offa = visa[p[b]];
            lena = 1 + ia[b] - ia[p[b]];
            vala = a[b] + visa[b] - visa[p[b]];
            break;
        }
        visa[p[b]] = visa[b] + a[b];
        ia[p[b]] = ia[b] + 1;
        b = p[b];
    }

    while(true) {
        if (ib[p[s]]) {
            offb = visb[p[s]];
            lenb = 1 + ib[s] - ib[p[s]];
            valb = a[s] + visb[s] - visb[p[s]];
            break;
        }
        visb[p[s]] = visb[s] + a[s];
        ib[p[s]] = ib[s] + 1;
        s = p[s];
    }

    

    cout << vala <<  " " << valb << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}