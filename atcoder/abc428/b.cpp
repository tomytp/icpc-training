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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    map<string, ll> cnt;
    forn(i, 0, n-k+1) {
        string sub = s.substr(i, k);
        cnt[sub]++;
    }

    ll bst = 0;
    set<string> st;
    for (auto& [ke, v] : cnt) {
        if (v > bst) {
            st.clear();
            bst = v;
            st.insert(ke);
        } else if (v == bst) {
            st.insert(ke);
        }
    }

    cout << cnt[*st.begin()] << ln;
    for (auto ke : st) {
        cout << ke << " ";
    }
    cout << ln;
    return 0;
}