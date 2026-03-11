#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<string> gaba = {
    "GGGgGGG", // 0
    "gggggGG", // 1
    "gGGGGGg", // 2
    "ggGGGGG", // 3
    "GggGgGG", // 4
    "GgGGGgG", // 5
    "GGGGGgG", // 6
    "ggGggGG", // 7
    "GGGGGGG", // 8
    "GgGGGGG", // 9
};

bool comp(string& a, string& num){
    bool ok = true;
    forn(i,0,7){
        if(a[i] == '*') continue;
        if(a[i] == num[i]) continue;
        ok = false;
    }
    return ok;
}

int main() {
    _;
    ll n; cin >> n;
    vector<string> leds(n, string(7,'a'));
    
    forn(i,0,n){
        forn(j,0,7){
            char aux;
            cin >> aux;
            if(aux == '+' || aux == '-'){
                leds[i][j] = '*';
            } else{
                leds[i][j] = aux;
            }
            
        }
    }

    forn(i,0,n){
        ll cnt = 0;
        ll resp = -1;
        forn(j,0,10){
            if(comp(leds[i], gaba[j])){
                cnt++;
                resp = j;
            }
        }
        if(cnt == 0 || cnt > 1){
            cout << '*';
            continue;
        }else{
            cout << resp;
        }
    }
    cout << ln;
    return 0;
}