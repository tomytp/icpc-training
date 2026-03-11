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
    v64 b(3), h(3);
    forn(i, 0, 3) cin >> b[i] >> h[i];
    ll a = 0; 
    forn(i,0,3) a += b[i] * h[i];
    
    ll sq = sqrt(a);
    if (sq*sq != a) { 
        cout << "NO\n";
        return;
    }

    bool valid = false;
    v64 perm = {0, 1, 2};

    do {
        ll b0 = b[perm[0]], h0 = h[perm[0]];
        ll b1 = b[perm[1]], h1 = h[perm[1]];
        ll b2 = b[perm[2]], h2 =h[perm[2]];
        if ((b0==sq && b1==sq && b2==sq && h0+h1+h2==sq) ||
            (h0==sq && h1==sq && h2==sq && b0+b1+b2==sq) ||
            (b0==sq && h1==h2 && h0+h1==sq && b1+b2==sq) ||
            (h0==sq && b1==b2 && b0+b1==sq && h1+h2==sq)) { 
            valid = true; 
            break; 
        }
    } while (next_permutation(perm.begin(), perm.end()));

    if (valid) cout << "YES\n";
    else cout << "NO\n";  
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}