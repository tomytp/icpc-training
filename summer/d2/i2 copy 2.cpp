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
const ll MAX = 100'000;

vector<pair<v64, ll>> vec;

void prep(){
    forn(i,0,MAX){
        v64 freq(10, 0);
        string s = to_string(i);
        
        for(char c: s) freq[c-'0']--;
        freq[0] -= 5 - sz(s);
        vec.push_back({freq, i});
    }
    sort(vec.begin(), vec.end());
}

vector<string> ans1;
vector<string> ans2;

void print(ll val){
    string s = to_string(val);
    while(sz(s) < 5) s.insert(s.begin(), '0');
    ans1.push_back(s);
}

void print2(ll val){
    string s = to_string(val);
    while(sz(s) < 5) s.insert(s.begin(), '0');
    ans2.push_back(s);
}

int solve1(ll n){
    _;
    v64 goal(10);

    forn(i,0,5) goal[i] = (n+1)/2;
    forn(i,5,10) goal[i] = (n)/2;

    ll idx = 0;
    forn(d,0,10){
        while (goal[d] > 0 && idx < MAX){
            auto& [freq, val] = vec[idx++];
            
            bool para = false;
            forn(i,0,10) if((-freq[i]) > goal[i]) para = true;
            if(para) continue;

            forn(i,0,10) goal[i] += freq[i];
            print(val);
        }     
        while (idx < MAX){
            auto& [freq, val] = vec[idx++];
            if(freq[d] == 0){
                idx--;
                break;
            };
        }
    }
    if(sz(ans1) != n) ans1.push_back("99991");
    return 0;
}

int solve2(ll n){
    _;
    v64 goal(10);

    forn(i,0,5) goal[i] = (n)/2;
    forn(i,5,10) goal[i] = (n+1)/2;

    ll idx = 0;
    forn(d,0,10){
        while (goal[d] > 0 && idx < MAX){
            auto& [freq, val] = vec[idx++];
            
            bool para = false;
            forn(i,0,10) if((-freq[i]) > goal[i]) para = true;
            if(para) continue;

            forn(i,0,10) goal[i] += freq[i];
            print2(val);
        }     
        while (idx < MAX){
            auto& [freq, val] = vec[idx++];
            if(freq[d] == 0){
                idx--;
                break;
            };
        }
    }
    return 0;
}

void check(ll n) {
    v64 cnt(10);
    set<string> ss;
    
    vector<string> ans;
    if(sz(ans1) == n){
        ans = ans1;
    }else{
        ans = ans2;
    }
    
    for(auto s : ans) {
        ss.insert(s);
        forn(i, 0, 5) {
            cnt[s[i] - '0']++;
        }
    }

    if (sz(ss) != sz(ans)) {
        cout << n << " REPETIDA" << ln;
        exit(0);
    }

    forn(i, 0, 10)
    forn(j, 0, 10) {
        if (abs(cnt[i] - cnt[j]) > 1) {
            debug(n);
            debugv(cnt);
            exit(0);
        }
    }
}

int main() {
    prep();
    forn(i, 1, 100000) {
        ans1.clear();
        ans2.clear();
        solve1(i);
        solve2(i);
        check(i);
        cout << i << ln;
    }
}