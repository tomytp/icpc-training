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
const ll MAX = 100'000;

void gat(ll b, ll diff){
    ll curr = b;
    cout << (char)('0' + curr);
    forn(j,1,5){
        ll x = diff%10;
        diff /= 10;
        curr = (curr+x)%10;
        cout << (char)('0' + curr);
    }
    cout << ln;
}

int main(){
    _;
    ll n; cin >> n;
    ll diff = 0;
    while(n > 10){
        if(diff != 1111) {
            forn(j,0,10) gat(j,diff);
            n -= 10;
        }
        diff++;
    }
    
    vector<string> aux = {
        "01234",
        "56789",
        "12345",
        "67890",
        "23456",
        "78901",
        "34567",
        "89012",
        "45678",
        "90123",
    };

    forn(i,0,n){
        cout << aux[i] << ln;
    }
    return 0;

}