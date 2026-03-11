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

void solve(ll t) {
    ll n; string s;
    cin >> n >> s;

    bool hasA = s.find('A') != s.npos;
    bool hasB = s.find('B') != s.npos;

    string ans;
    if (!hasA) {
        ans = "Bob";
    } else if (!hasB) {
        ans = "Alice";
    } else if (s.back() == 'A') {
        ans = "Alice";
    } else {
        ll lastB = s.find_last_of('B');
        bool hasAA = false;
        forn(i, 0, lastB-1){
            if (s[i] == 'A' && s[i+1] == 'A'){ hasAA = true; break; }
        }
        ans = hasAA ? "Alice" : "Bob";
    }
    cout << "Case #" << t << ": " << ans << ln;
}

int main(){
    _;
    ll t; cin >> t;
    forn(i, 0, t) solve(i+1);
    return 0;
}