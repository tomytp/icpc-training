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

ll amt = 0;
ll ask(ll t1, ll t2, ll x, ll y){
    assert(amt < 13);
    cout << "? " << t1 << " " << t2 << " " << x << " " << y << endl;
    cout.flush();
    ll r; cin >> r;
    amt++;
    return r;
}

void solve(){   
    amt = 0;
    ll n; cin >> n;
    ll cnt = 0;
    ll curr = n;
    ll x = ask(1,2,1,1);

    if(x == n){
        cout << "! 1\n";
        cout.flush();
        return;
    }

    while(curr%2 == 0){
        cnt++;

        if(curr != 2){
            x = ask(1,1,(curr/2) + 1, 1);
        }else{
            x = 0;
        }
        if(x < curr/2) break;
        curr /= 2;
    }

    if(curr%2 == 0) cnt++;
    cout << "! " << (cnt)%2 << endl;
    cout.flush();
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) {
        cout.flush();
        solve();
        cout << endl;
        cout.flush();
    }

    return 0;
}