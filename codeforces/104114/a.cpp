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
    _; string s, t; cin >> s >> t;
    vector<set<ll>> idx(26);
    ll n = sz(s);
    ll m = sz(t);
    forn(i, 0, n){
        idx[s[i]-'a'].insert(i);
    }


    ll cnt = 1, curr = -1;
    forn(i, 0, m){  
        debug(curr);

        auto it = idx[t[i]-'a'].upper_bound(curr);
        if(it == idx[t[i]-'a'].end()){
            cnt ++;
            it = idx[t[i]-'a'].begin();
        }

        curr = *it;
    }

    cout << cnt << ln;

    return 0;
}