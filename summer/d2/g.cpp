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

int main(){
    _;
    ll x = 1;
    ll cnt = 0;
    while (x != -1 && cnt < 297) {
        cout << "get" << endl;
        cin >> x;
        cnt++;
    }
    cout << "put 1" << endl; 
    cout << "put 2" << endl;

    cout << "get" << endl;
    cin >> x;
    if (x == 1) {
        cout << "queue" << endl;
    } else {
        cout << "stack" << endl;
    }
    return 0;
}