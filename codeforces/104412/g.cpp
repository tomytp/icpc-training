#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll n, T; cin >> n >> T;

    ll best_self = 0;
    ll best_in = 0;
    ll best_out = 0;

    ll resp = 0;

    v64 deg_in(n), deg_out(n);

    forn(t,0,T){
        ll a, b; cin >> a >> b;
        a--, b--;

        deg_in[b]++;
        deg_out[a]++;

        resp += deg_in[a] + deg_out[b] - (a==b ? 1 : 0);
        best_in = max(best_in, deg_in[b]);
        best_out = max(best_out, deg_out[a]);
        best_self = max(best_self, deg_in[a]+deg_out[a] + 1);
        best_self = max(best_self, deg_in[b]+deg_out[b] + 1);

        cout << resp << " " << max(best_in+best_out, best_self) << ln;
    }
    return 0;
}