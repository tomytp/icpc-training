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

map<char,ll> dict_vai = {{'0', 0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}, {'A',10}, {'B',11}, {'C',12}, {'D',13}, {'E',14}, {'F',15}};
vector<char> dict_volta = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

ll vai(string s){
    return dict_vai[s[0]]*16+dict_vai[s[1]];
}

string volta(ll n){
    string s(2, '0');
    debug(n);
    s[1] = dict_volta[(n%16+16)%16];
    n /= 16;
    s[0] = dict_volta[(n%16+16)%16];
    debug(s);
    return s;
}

void encrypt(string s){
    vector<ll> byte(8);
    forn(i, 0, 8){
        string curr = {s[2*i], s[2*i+1]};
        byte[i] = vai(curr);
    }

    ll new_byte = 0; 
    forn(i, 0, 8){
        if(byte[i] & 1) new_byte += 1<<i;
    }

    string new_byte_hex = volta(new_byte);
    s = s + new_byte_hex;
    cout << s << ln;
}

void decrypt(string s){
    vector<ll> byte(8);
    forn(i, 0, 8){
        string curr = {s[2*i], s[2*i+1]};
        byte[i] = vai(curr);
    }

    string curr = {s[16], s[17]};
    ll new_byte = vai(curr);

    ll agree = 0;
    forn(i, 0, 8){
        if( (byte[i] & 1)<<i == (new_byte & (1<<i)) ) agree++;
    }

    if(agree < 4) new_byte = ((1<<8) -1)^new_byte;

    forn(i, 0, 8){
        if( (byte[i] & 1)<<i != (new_byte & (1<<i)) ) byte[i] = ((1<<8) -1)^byte[i];
    }

    string new_s;
    forn(i, 0, 8){
        new_s += volta(byte[i]);
    }


    cout << new_s << ln;
}

int main(){
    _;ll n; cin >> n; 
    string enc; cin >> enc;
    
    forn(i, 0, n){
        string s; cin >> s;
        if(enc == "encrypt") encrypt(s);
        if(enc == "decrypt") decrypt(s);
    }

    return 0;
}