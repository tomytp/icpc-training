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

int main(){
    _;
    string s; cin >> s;
    string tmp = "";
    ll cnt = 0;
    vector<string> v;
    ll n = sz(s);
    forn(i, 0, n) {
        tmp.push_back(s[i]);
        if (s[i] == '(') cnt++;
        else cnt--;
        if (cnt == 0) {
            v.push_back(move(tmp));
            tmp = "";
        }
    }
    string nw = "";
    forn(i, 1, v.size() + 1) {
        ll c = i % v.size();
        forn (j, 0, sz(v[c])) {
            nw.push_back(v[c][j]);
        }
    }

    if (nw == s) {
        cout << "no" << ln;
    } else {
        cout << nw << ln;
    }
    return 0;
}