#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

int main(){
    _;
    ll n, m; cin >> n >> m;
    vector<p64> vals(n);
    for (auto& [a, b] : vals) cin >> a >> b;
    v64 swaps(m + 1);
    v64 started(n, -1);
    ll sq = sqrt(m);
    ll cnt = 0;

    vector<v64> mat(sq+5);
    forn(i, 0, sq+5) {
        mat[i] = v64(i+1);
    }

    forn(t, 0, m) {
        ll op, k; cin >> op >> k;
        k--;
        cnt += swaps[t];
        forn(p, 1, sq+1) {
            cnt += mat[p][t % p];
        }

        auto [x, y] = vals[k];
        if (op == 1) {
            // added
            started[k] = t;
            if (x + y > sq) {
                ll curr = t;
                while (curr <= m) {
                    if (curr + x <= m) swaps[curr + x]++;
                    if (curr + x + y <= m) swaps[curr + x + y]--;
                    curr += x + y;
                }
            } else {
                ll tmod = t % (x+y);
                mat[x+y][(tmod + x) % (x+y)]++;
                mat[x+y][tmod]--;
            }
        } else {
            // removed
            if (x + y > sq) {
                ll curr = started[k];
                while (curr <= m) {
                    if (curr + x <= m) swaps[curr + x]--;
                    if (curr + x + y <= m) swaps[curr + x + y]++;
                    curr += x + y;
                }
            } else {
                ll tmod = started[k] % (x+y);
                mat[x+y][(tmod + x) % (x+y)]--;
                mat[x+y][tmod]++;
            }
            
            ll d = (t - started[k]) % (x + y);
            if (d >= x) cnt--; 
        }

        cout << cnt << ln;
    }
    return 0;
}