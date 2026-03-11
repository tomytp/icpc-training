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

void minimize(string mini, string mize){
    if(mize.empty()){
        cout << mini << ln;
        return;
    }
    char c = mize.back() + 32; 

    debug(mini);

    mize.pop_back();
    mini.push_back(c);

    minimize(mini, mize);

    if(mini.size() == 1) return;
    if(mini[sz(mini)-1] == 's' && mini[sz(mini)-2] == 's'){
        mini.pop_back();
        mini.pop_back();
        mini.push_back('B');
        minimize(mini, mize);
    }
}

int main(){
    _; string s, s2 = ""; cin >> s;
    reverse(s.begin(), s.end());
    minimize(s2,s);
    return 0;
}