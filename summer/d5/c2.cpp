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

string s;

ll ask(ll t1, ll t2, ll x, ll y){
    cout << "? " << t1 << " " << t2 << " " << x << " " << y << endl;
    ll r; cin >> r;
    return r;
}

void solve(){
    ll n; cin >> n;
    ll cnt = 0;
    ll curr = n;
    while(curr%2 == 0){
        cnt++;
        ll x = ask(1,1,(curr/2) + 1, 1);
        if(x < curr/2) break;
        curr /= 2;
    }

    ll x = ask(1,2,1,n-curr+1);
    if(x >= curr){
        cout << "! " << 1 << endl;
    }else{
        cout << "! " << (cnt+1)%2 << endl;
    }
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();

    return 0;
}