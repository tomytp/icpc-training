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
const ll MAXN = 500;

int main(){
    _;
    v64 dice(5);
    forn(i, 0, 5) cin >> dice[i];
    ll least = dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
    ll mean = (5)*dice[0] + (7)*dice[1]+ (9)*dice[2] + (13)*dice[3] + (21)*dice[4];

    ll low = mean - mean%2, up = mean + mean%2;
    low /= 2;
    up /= 2;
    
    while(low >= least){
        if(low != up) cout << up<< " ";
        cout << low << " ";

        up += 1;
        low -= 1;
    }

    cout << ln;

    return 0;
}