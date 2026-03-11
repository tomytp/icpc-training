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
const ll fat3 = 6;
const ll fat5 = 120;

vector<string> vec10;
map<string, ll> mp10;

vector<string>  vec7;
map<string, ll> mp7;

vector<string>  vec5;
map<string, ll> mp5;

vector<string> vec3;
map<string, ll> mp3;

map<ll, char> mp = {{1, 'A'}, {5, 'B'}, {7, 'C'}};

void prep(){
    string base10 = "ABCDEFGHIJ";
    ll cnt10 = 0;
    do{
        vec10.push_back(base10);
        mp10[base10] = cnt10;
        cnt10++;
    } while(next_permutation(base10.begin(), base10.end()));

    string base7 = "ABCDEFG";
    ll cnt7 = 0;
    do{
        vec7.push_back(base7);
        mp7[base7] = cnt7;
        cnt7++;
    } while(next_permutation(base7.begin(), base7.end()));

    
    string base5 = "ABCDE";
    ll cnt5 = 0;
    do{
        vec5.push_back(base5);
        mp5[base5] = cnt5;
        cnt5++;
    } while(next_permutation(base5.begin(), base5.end()));


    string base3 = "ABC";
    ll cnt3 = 0;
    do{
        vec3.push_back(base3);
        mp3[base3] = cnt3;
        cnt3++;
    } while(next_permutation(base3.begin(), base3.end()));
}

tuple<ll ,ll, ll> decomp(ll y){
    ll x1 = y%fat3;
    y -= x1;
    y /= fat3;
    ll x2 = y%fat5;
    y -= x2;
    y /= fat5;
    ll x3 = y;
    return {x1, x2, x3};
}

ll comp(ll x1, ll x2, ll x3){
    return x1 + x2*fat3 + x3*fat3*fat5;
}

void coach() {
    string s; cin >> s;

    ll cnt = mp10[s];
    debug(cnt);

    auto [x1, x2, x3] = decomp(cnt);

    
    debug(x1);
    debug(x2);
    debug(x3);

    string s1 = vec3[x1];    
    string s2 = vec5[x2];    
    string s3 = vec7[x3];    
    
    forn(i,0,3){
        if(s1[i] == 'A') cout << "A" << " ";
        if(s1[i] == 'B') cout << s2 << " ";
        if(s1[i] == 'C') cout << s3 << " ";
    }
    cout << ln;
}

void team() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<string> aux(10);
    aux[sz(s1)] = s1;
    aux[sz(s2)] = s2; 
    aux[sz(s3)] = s3;

    string s5 = aux[5];
    string s7 = aux[7];

    string perm = {mp[sz(s1)], mp[sz(s2)], mp[sz(s3)]};
    
    ll x1 = mp3[perm];
    ll x2 = mp5[s5];
    ll x3 = mp7[s7];

    debug(x1);
    debug(x2);
    debug(x3);
    ll y = comp(x1, x2, x3);
    debug(y);

    cout << vec10[y] << ln;
}

int main(){
    _;
    prep();
    string s; cin >> s;
    ll t; cin >> t;
    if (s == "coach") {
        while (t--) coach();
    } else {
        while (t--) team();
    }
    return 0;
}