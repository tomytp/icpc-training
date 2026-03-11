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

void solve(){
    ll p1, p2, p3;
    char c1, c2, c3;
    cin >> c1 >> p1;
    cin >> c2 >> p2;
    cin >> c3 >> p3;

    ll a_amt = 0;
    if(c1 == 'A') a_amt++;
    if(c2 == 'A') a_amt++;
    if(c3 == 'A') a_amt++;

    ll inv = 0;

    if(a_amt == 1){
        if(c1 == 'B') p1--;
        if(c2 == 'B') p2--;
        if(c3 == 'B') p3--;
        inv = 1;
    }
    if(a_amt == 2){
        if(c1 == 'A') p1--;
        if(c2 == 'A') p2--;
        if(c3 == 'A') p3--;
        inv = 1;
    }


    ll imp = 0;
    ll parsum = 0;
    ll paramt = 0;
    if(p1%2 == 0){
        parsum += p1;
        paramt++;
    }else{
        imp = p1;
    }
    
    if(p2%2 == 0){
        parsum += p2;
        paramt++;
    }else{
        imp = p2;
    }
    
    if(p3%2 == 0){
        parsum += p3;
        paramt++;
    }else{
        imp = p3;
    }

    if(paramt == 3){
        cout << (0^inv) << ln;
        return;
    }
    if(paramt <= 1){
        cout << (1^inv) << ln;
        return;
    }
    
    if(imp > parsum){
        cout << (0^inv) << ln;
    }else{
        cout << (1^inv) << ln;
    }
}  
int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();

    return 0;
}