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

string next(string s){
    map<char,ll> m;
    for(auto x : s){
        m[x]++;
    }

    string s_new = "";
    for(auto p : m){
        string aux = "";
        ll num = p.second;
        while(num > 0){
            aux.push_back(num%10 + '0');
            num = num/10;
        }
        reverse(aux.begin(), aux.end());
        s_new = s_new + aux;
        s_new.push_back(p.first);
    }

    return s_new;
}

int main(){
    _; string s1, s2; cin >> s1 >> s2;
    set<string> conj;
    conj.insert(s2);
    forn(i, 0, 100){
        debug(i);
        auto it = conj.find(s1);
        if(*it == s2){
            cout << i+1 << ln;
            return 0;
        }
        if(it != conj.end()){
            cout << "Does not appear" << ln;
            return 0;
        }
        conj.insert(s1);

        s1 = next(s1);
        if(s1 == "") break;
    }
    
    cout << "I'm bored" << ln;
    return 0;
}