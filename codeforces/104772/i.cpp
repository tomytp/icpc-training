#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln endl

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll n;

ll ask(ll i, ll j) {
    cout << i+1 << " " << j+1 << ln;
    ll x; cin >> x;
    if (x == n) exit(0);
    return x;
}

void f(bitset<10>& bs, ll idx, ll i, bitset<10>& bst, ll& bstval){
    if(idx == -1) return;
    f(bs, idx-1, i, bst, bstval);
    bs[idx] = bs[idx]^1;
    ll nval = ask(i, i+idx);
    if (nval > bstval) {
        bst = bs;
        bstval = nval;
    }
    f(bs, idx-1, i, bst, bstval);
}

void solve(ll i) {
    bitset<10> curr;
    bitset<10> best;
    ll bstval = 0;
    f(curr, n-i-1, i, best, bstval);
    curr[n-1] = curr[n-1]^1;
    ll nval = ask(i, n-1);
    if (nval > bstval) {
        best = bitset<10>();
        bstval = nval;
    }
    debug(best);
    debug(bstval);
    forn(j, 0, n-i) {
        if (!best[j]) continue;
        ask(i, i+j);
    }
    debug("------------");
}

int main() {
    _;
    cin >> n;

    ll st; cin >> st;
    forn(i, 0, n) {
        solve(i);
    }

    return 0;
}