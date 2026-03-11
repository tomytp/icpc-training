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

vector<string> th = {"", "0", "00", "000"};
vector<string> hu = {"", "1", "11", "111", "12", "2", "21", "211", "2111", "10"};
vector<string> te = {"", "4", "44", "444", "43", "3", "34", "344", "3444", "41"};
vector<string> un = {"", "6", "66", "666", "65", "5", "56", "566", "5666", "64"};


string to_roman(ll n){
    string uni = un[n%10];
    n/=10;
    string ten = te[n%10];
    n/=10;
    string hun = hu[n%10];
    n/=10;
    string tho = th[n%10];

    return tho + hun + ten + uni;
}


int main(){
    _;  

    ll t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        vector<string> vec;
        forn(i,l,r+1){
            vec.push_back(to_roman(i));
        }
        sort(vec.begin(), vec.end());

        ll ans = 0;
        do{
            string s;
            for(auto ss: vec) s += ss;
            ll p1 = 0;
            ll p2 = 0;    
            ll curr = 0;
            while(p2 < sz(s)){
                if(s[p1] == s[p2]){
                    p2++;
                    continue;
                }
                curr = max(curr, p2-p1);
                p1 = p2;    
            }
            curr = max(curr, p2-p1);
            ans = max(curr, ans);
        }while(next_permutation(vec.begin(), vec.end()));
        cout << ans << ln;
    }
    
    return 0;
}