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

ll convert(char c){
    if(c == 'A') return 1;
    if(c == 'T') return 10;
    if(c == 'J') return 10;
    if(c == 'Q') return 10;
    if(c == 'K') return 10;
    return c-'0';
}

int main(){
    _;
    ll n; cin >> n;
    vector<char> v(n);
    forn(i, 0, n) cin >> v[i];
    map<char, ll> mp;
    forn(i, 0, n) {
        mp[v[i]]++;
    }

    v64 dp(16, 0);
    dp[0] = 1;

    forn(i,0,n){
        ll val = convert(v[i]);
        for(ll j = 15; j >=0; j--){
            if(j - val < 0) continue;
            dp[j] += dp[j-val];
        }
    }

    ll resp = 2*dp[15];
    
    for(auto p : mp){
        resp += p.second*(p.second-1); 
    }


    // sequencias

    v64 aux;
    string keys = "A23456789TJQK";
    for(auto k : keys) {
        if (mp[k] == 0) {
            if (aux.size() >= 3) {
                ll temp = 1;
                forn(i, 0, aux.size()) {
                    temp *= aux[i];
                }
                resp += temp * aux.size();
                // conta
            }
            aux.clear();
        } 

        if (mp[k]) {
            aux.push_back(mp[k]);
        }
    }

    if (aux.size() >= 3) {
            ll temp = 1;
            forn(i, 0, aux.size()) {
                temp *= aux[i];
            }
            resp += temp  * aux.size();
            debug(temp);
            // conta        
    }
    
    cout << resp << ln;

    return 0;
}