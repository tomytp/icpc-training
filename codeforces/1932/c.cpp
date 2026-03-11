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
    v64 a(n), add;
    forn(i, 0, n) cin >> a[i];
    string s; cin >> s;
    ll l = 0, r = n-1;
    forn(i, 0, n){
        if(s[i] == 'L') add.push_back(a[l++]);
        if(s[i] == 'R') add.push_back(a[r--]);
    }
    reverse(add.begin(), add.end());
    v64 ans;
    ll prod = 1;
    forn(i,0,n){
        prod = (prod*add[i]) % m;
        ans.push_back(prod);
    }
 
    reverse(ans.begin(), ans.end());
    forn(i, 0, n) cout << ans[i] << " \n"[i==n-1];
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}