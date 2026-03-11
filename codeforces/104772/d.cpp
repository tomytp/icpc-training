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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll getord(ll m){
    if(m == 1) return 1;
    ll g = 1;
    ll pot = 10%m;

    while(pot != 1){
        g++;
        pot = (10*pot)%m;
    }
    return g;
}

int solve(ll n) {
    ll aaa = n;
    ll a=0, b=0;

    while(n%2 == 0){
        a++;
        n = n/2;
    }
    while(n%5 == 0){
        b++;
        n = n/5;
    }

    ll g = getord(n);

    v64 idxs;

    forn(i,0,aaa){
        idxs.push_back(g*i + max(a,b));
    }

    string s(idxs.back()+1, '0');
    
    for(ll x: idxs){
        s[x] = '1';
    }
    reverse(s.begin(), s.end());
    // if(s.size() > 1'000'000) cout << aaa << " ------" << ln;
    // if(s[0] == '0') cout << aaa << " ------#" ln;
    cout << s << ln;
    return 0;
}

int main(){
    _; 
    ll n; cin >> n;
    solve(n);

    // forn(i,1,1001){
    //     cout << i << ln;
    //     solve(i);
    // }

}