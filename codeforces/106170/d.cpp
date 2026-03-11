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
    ll n, m; cin >> n >> m;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    
    ll songs = m;
    ll negoff = 0;
    ll mn = -1, mx = 0;
    forn(i, 0, n) {
        if ((n-i) * (v[i] - negoff) > m){
            if (m % (n-i) == 0)
            // acaba aqui
        } else {
            // continua
            if (mn == -1) {
                mn = v[i];
            }
            mx = v[i];
        }
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}