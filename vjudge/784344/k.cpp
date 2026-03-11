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

void test(v64& vec){
    if(vec[8] >= 5) return;
    if(vec[0] <= vec[8]) return;
    forn(i,0,vec[8]) if(vec[i] == 8) continue;
    }
}   

int main(){
    _;
    ll n = 9;
    v64 vec = {0,1,2,3,4,5,6,7,8};

    do{
        test(vec);
    }while(next_permutation(vec.begin(), vec.end()));

    return 0;
}