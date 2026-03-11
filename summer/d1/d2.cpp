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
    ll zeros, ones, orr; cin >> zeros >> ones >> orr;
    ll andd = (zeros+ones-1-orr);

    ll n = zeros + ones;

    v64 bits(n,1);
    v64 op(n-1,1);
    forn(i,0,zeros) bits[i] = 0;

    forn(i,0,orr) op[i] = 0;
    ll best = 0;
    do{
        do{
            ll resp = 0;
            forn(i,0,n-1){
                if(op[i] == 0) resp += bits[i]|bits[i+1];
                else resp += bits[i]&bits[i+1];
            }
            best = max(best, resp);
        }while (next_permutation(op.begin(), op.end()));
    } while (next_permutation(bits.begin(), bits.end()));
    cout << best << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}