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

vector<v64> torre1;
vector<v64> torre2;

void solve(){
    ll s0 = torre2[0].size();
    ll s1 = torre2[1].size();

    
    while(true){
        ll bound;
        if(torre1[0].size() == 0) bound = INF;
        else *prev(torre1[0].end());
        
        if(torre1[1].size() == 0) break;
        
        ll novo = *prev(torre1[1].end());
        if(novo <= bound){
            torre1[0].push_back(novo);
            torre1[1].pop_back();
        }else{
            break;
        }
    }
    
    while(true){
        
        ll bound;
        if(torre2[0].size() == 0) bound = INF;
        else *prev(torre2[0].end());
        
        if(torre2[1].size() == 0) break;
        
        ll novo = *prev(torre2[1].end());
        if(novo <= bound){
            torre2[0].push_back(novo);
            torre2[1].pop_back();
        }else{
            break;
        }
    }

    if(torre1 == torre2){
        cout << "S" << ln;
    }else{
        cout << "N" << ln;
    }
}

int main(){
    _;
    ll t; cin >> t;
    ll sum1 = 0;
    ll sum2 = 0;
    torre1.resize(t);
    torre2.resize(t);
    
    forn(i,0,t){
        ll k; cin >> k;
        torre1[i].resize(k);
        forn(j,0,k){
            cin >> torre1[i][j];    
            sum1++;
        }

        cin >> k;
        torre2[i].resize(k);
        forn(j,0,k){
            cin >> torre2[i][j];    
            sum2++;
        }
    }
    
    if(sum1 != sum2){
        cout << "N" << ln;
        return 0;
    }

    if(t == 2){
        solve();
        return 0;
    }
    else{
        cout << "S" << ln;
    };

    return 0;
}
