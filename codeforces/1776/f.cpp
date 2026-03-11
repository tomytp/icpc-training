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

void solve(){
    ll n, m; cin >> n >> m;
    vector<p64> edges(m);
    vector<v64> g(n);

    forn(i,0,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        if(a > b) swap(a,b);
        edges[i] = {a,b};
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if(m == n*(n-1)/2){
        cout << 3 << ln;
        forn(i,0,m){
            auto [a,b] = edges[i];
            if(a == 0 && b == 1){
                cout << 3 << " ";
            }else if(a==0){
                cout << 1 << " ";
            }else if(a==1){
                cout << 2 << " ";
            }else{
                cout << 3 << " ";
            }
        }
        cout << ln;
        return;
    }

    ll v = -1;
    forn(i,0,n){
        if(g[i].size() < n-1){
            v = i;
            break;
        }
    }

    cout << 2 << ln;
    forn(i,0,m){
        auto [a,b] = edges[i];
        if(a == v || b == v){
            cout << 1 << " ";
        }else{
            cout << 2 << " ";
        }
    }
    cout << ln;
    return;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
