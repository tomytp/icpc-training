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

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    string out(n, '+');
    ll top = 0, bot = 0, neg = 0;
    for (auto c : s) {
        if (c == '0') top++;
        if (c == '1') bot++;
        if (c == '2') neg++;
    }

    forn(i, 0, top) {
        out[i] = '-';
    }
    forn(i, 0, bot) {
        out[n-1-i] = '-';
    }
    forn(i, top, top+neg) {
        if (out[i] == '+') out[i] = '?';
    }
    forn(i, bot, bot+neg) {
        if (out[n-i-1] == '+') out[n-1-i] = '?';
    }

    if (k == n) {
        forn(i, 0, n) out[i] = '-';
    }

    cout << out << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}