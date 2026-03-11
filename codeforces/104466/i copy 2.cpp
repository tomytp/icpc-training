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
const ll MAX = 1'000'005;

int main(){
    _;
    ll n; cin >> n;

    v64 sapo(n);
    forn(i, 0, n) cin >> sapo[i];
    ll q; cin >> q;
    set<ll> s;

    forn(i,0,MAX+q){
        s.insert(i);
    }

    forn(i,0,n) s.erase(sapo[i]);
    
    forn(kk, 0, q) {
        ll x; cin >> x; x--;
        ll curr = sapo[x];
        ll prox = *s.lower_bound(curr);
        s.erase(prox);
        s.insert(curr);
        sapo[x] = prox;
        cout << prox << ln;
    }

    // forn(i,0,n) cout << sapo[i] << " ";; cout << ln;
    return 0;
}