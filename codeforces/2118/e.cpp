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

void solve() {
    ll n, m; cin >> n >> m;
    vector<v64> v(n, v64(m));

    ll a = m/2, b = m/2 + 1;
    ll counter = 1;
    forn(i, 0, m+1) {
        if (a >= 0) v[n/2][a--] = counter++;
        if (b < m) v[n/2][b++] = counter++;
    }

    ll na = (n/2) - 1;
    ll nb = (n/2) + 1;

    forn(i, 0, n+1) {
        if (!(i & 1)) {
            a = m-1, b = 0;
        }else {
            a = 0, b = m-1;
        }
        forn(j, 0, m+1) {
            if (!(i & 1)) {
                if (na >= 0 && a >= 0) v[na][a] = counter++;
                if (nb < n && b < m) v[nb][b] = counter++;
                a--;b++;
            }else {
                if (na >= 0 && a < m) v[na][a] = counter++;
                if (nb < n && b >= 0) v[nb][b] = counter++;
                a++;b--;
            }
        }
        na--;nb++;
    }

    vector<p64> ans(n*m);

    forn(i, 0, n) {
        forn(j, 0, m) {
            debug(v[i][j]-1);
            ans[v[i][j]-1] = {j + 1, i + 1};
        }
    }

    forn(i, 0, n*m) {
        cout << ans[i].second << " " << ans[i].first << ln;
    }

    // forn(i, 0, n)
    // forn(j, 0, m)
    // cout << v[i][j] << " \n"[j==m-1];
    // cout << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}