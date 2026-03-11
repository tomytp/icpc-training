#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sz(x) ((ll) x.size())

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX_D = 4010;

ll convert(string s){
    ll pot2 = 1, resp = 0;
    for(ll i = sz(s)-1; i>= 0; i--){
        if(s[i] == '1') resp += pot2;
        pot2 *= 2;
        if(resp > MAX_D) return -1;
    } 

    return resp; 
}

string sum(string& m, string& s){
    string ans;

    ll n = max(sz(m), sz(s));
    bool vaium = false;
    forn(i,0,n){
        ll curr = 0;
        if(vaium){
            vaium = false;
            curr++;
        }

        if(i < sz(m) && m[i] == '1') curr++;
        if(i < sz(s) && s[i] == '1') curr++;

        if(curr >= 2){
            curr -= 2;
            vaium = true;
        }

        ans.push_back('0'+curr);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string bin(ll s){
    string binario = "";
    while(s > 0){
        if(s%2 == 1) binario.push_back('1');
        else binario.push_back('0');
        s /= 2;
    }

    reverse(binario.begin(), binario.end());
    return binario;
}

int main() {
    _; string s, dst, m; cin >> s >> dst >> m;
    ll d = convert(dst);
    ll counter = 0;

    while(counter < MAX_D){
        counter++;
        m.pop_back();
        debug(d);
        if(d!= -1 && counter%d == 0) m = sum(m, s);
        if(m == "") break;
    }
    
    if(counter >= MAX_D)cout << "Infinite money!" << ln;
    else cout << bin(counter) << ln;

    return 0;
}