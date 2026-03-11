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

map<char,ll> hexa = {{'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
vector<string> sol = {"", "E", "D", "C", "B","A","AE","AD", "AC", "AB", "AA","AAE","AAD","AAC","AAB"};

int main(){
    _; string s; cin >> s;
    string solve;
    ll sum = 0;
    bool mult4 = (s.back() == 'C');
    forn(i, 0, sz(s)) sum += hexa[s[i]];

    if(!mult4){
        sum += 12;
    }

    solve = sol[sum%15];
    if(!mult4) solve += 'C';

    if(sum%15 == 0 && mult4){
        cout << "OK" << ln;
    } else if(sum%15 == 0 && !mult4){
        cout << "C" << ln;
    } else {
        sort(solve.begin(), solve.end());
        cout << solve << ln;
    }

    return 0;
}