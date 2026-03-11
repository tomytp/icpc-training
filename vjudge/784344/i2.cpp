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

ll lcp(ll ia, ll ib) {
    ll sum = 0;
    for (ll i = 0; i < sz(a[ia]) && i < sz(b[ib]); i++) {
        if (a[ia][i] == b[ib][i]) sum++;
        else return sum;
    }
    return sum;
}

int main(){
    _;
    cin >> n;
    a.resize(n);
    b.resize(n);

    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    v64 perm(n);
    iota(perm.begin(), perm.end(), 0ll);

    ll resp = 0;
    vector<p64> v;
    do {
        ll ans = 0;
        vector<p64> vv;
        forn(i, 0, n) {
            ans += lcp(i, perm[i]);
            vv.emplace_back(i, perm[i]);
        }
        if (ans > resp) {
            v = vv;
            resp = ans;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << resp << ln;

    return 0;
} 