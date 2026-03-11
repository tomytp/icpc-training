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
    ll n, m, p, s; cin >> n >> m >> p >> s;
    vector<bitset<20>> inf(n, bitset<20>((1<<n)-1));
    forn(i, 0, m) {
        ll a, b; cin >> a >> b;
        a--, b--;
        inf[a][b] = false;
        inf[b][a] = false;
    }
    ll ans = 0;
    forn(i, 0, (1<<n)) {
        bitset<20> curr = bitset<20>(i);
        ll ct = 0;
        forn(j, 0, p) if (curr[j]) ct++;
        if (ct != 1) continue;
        ct = 0;
        forn(j, p, p+s) if (curr[j]) ct++;
        if (ct != 1) continue;
        bitset<20> peixe = curr;
        forn(j, 0, n) {
            if (curr[j]) peixe &= inf[j];
        }
        if (peixe == curr) ans++;

    }  
    cout << ans << ln;
    // forn(i, 0, n) {
    //     cout << inf[i] << ln;
    // }
    return 0;
}