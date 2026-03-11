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
    ll n, k; cin >> n >> k;
    if (k & 1) {
        forn (i, 0, k) cout << n << " \n"[i==k-1];
        return;
    }

    if ((n & (n - 1)) == 0) {
        cout << 0 << " ";
        forn(i, 1, k) cout << n << " \n"[i == k - 1];
        return;
    }


    v64 ans(k, n);
    ans[k - 1] = 0;
    ll cur = (k - 1) * n;

    ll fb = -1;
    for (ll i = 62; i >= 0; i--) {
        if ((n >> i) & 1) {
            fb = i;
            break;
        }
    }

    ll a = 1ll << fb;
    ll b = n^ (1ll << fb);

    for (ll i = fb - 1; i >= 0; i--) {
        if (n & (1ll << i)) {
        } else if (((a|(1ll << i)) <= n) && ((b|(1ll << i)) <= n)) {
            a |= (1ll << i);
            b |= (1ll << i);
        }
    }
    if (a + b > n) {
        cur += (a+b)-n;
        ans[k-2] = a;
        ans[k-1] = b;
    }

    if (k >= 4 && (n % 2 == 0)) {
        v64 bt;
        forn(i, 0, 63) if ((n >> i) & 1) bt.push_back(1ll << i);
        
        if (sz(bt) >= 3) {
            ll u = bt[0], v = bt[1], w = bt[2];
            ll p = (u | v | w) | 1; 
            
            if (p <= n) {
                ll s4 = ((n ^ u) | 1) + ((n ^ v) | 1) + ((n ^ w) | 1) + p;
                if ((k - 4) * n + s4 > cur) {
                    fill(ans.begin(), ans.end(), n);
                    ans[k - 4] = (n ^ u) | 1;
                    ans[k - 3] = (n ^ v) | 1;
                    ans[k - 2] = (n ^ w) | 1;
                    ans[k - 1] = p;
                }
            }
        }
    }

    forn(i, 0, k) cout << ans[i] << " \n"[i==k-1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}