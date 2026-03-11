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
    ll n; cin >> n;
    vector<v64> g(n);
    v64 groups(n);
    v64 resp(n);
    ll root = -1;
    forn(i,0,n){
        ll p; cin >> p;
        p--;
        if(p == -1){
            root = i;
            continue;
        }
        g[i].push_back(p);
        g[p].push_back(i);
    }

    forn(i,0,n) cin >> groups[i];
    v64 freq(n+1);
    ll amt = 0;

    function<ll (ll, ll)> dfs = [&](ll u, ll p){
        freq[groups[u]]++;
        if(freq[groups[u]] == 1) amt++;
        resp[u] = amt;

        for(ll v: g[u]) if(v != p){
            dfs(v,u);
        }
    
        freq[groups[u]]--;
        if(freq[groups[u]] == 0) amt--;

        return 0ll;
    };
    dfs(root, -1);

    forn(i,0,n) cout << resp[i] << " ";; cout << ln;
    return 0;
}