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

map<ll, char> div_char;
map<char, ll> char_div;

void prep(){
    ll cnt = 0;
    forn(i,1,901){
        if(900%i == 0){
            div_char[i] = (char)('a'+cnt);
            char_div['a'+cnt] = i;
            cnt++;
        }
    }
}

void encode(){
    string s;
    cin >> s;
    trace(cout << "decode" << ln;);
    if(sz(s) == 900){
        forn(i,0,900){
            cout << s[i] << ln;
        }
        cout << "#" << ln;
        return;
    }
    ll k = char_div[s.back()];
    
    forn(i,0,k){
        forn(j,0,900/k){
            cout << s[i*(900/k)+j];
        }
        cout << ln;
    }
    cout << "#" << ln;
}

void decode(){
    vector<string> vec;
    string s;
    while(s != "#"){
        cin >> s;
        vec.push_back(s);
    }
    vec.pop_back();

    if(sz(vec) == 900){
        forn(i,0,900){
            cout << vec[i];
        }
        cout << ln;
        return;
    }

    debugv(vec); 
    for(auto r : vec) cout << r;
    cout << div_char[sz(vec)] << ln;
}

int main(){
    _;
    prep();
    string t; cin >> t;
    if(t == "encode"){
        encode();
    }else{
        decode();
    }
    
    
    return 0;
}