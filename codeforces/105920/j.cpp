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

int main(){
    _;
    ll n, k; cin >> n >> k;
    v64 v(n*2), diff(n*2);
    forn(i, 0, n) cin >> v[i], v[i + n] = v[i];
    forn(i, 0, n*2) diff[i] = v[i] - i*k;

    v64 ans(n*2, -1);
    stack<ll> s;
    for (ll i = n*2-1; i >= 0; i--) {
        while(s.size() && (diff[s.top()] >= diff[i])) {
            debug(diff[i]);
            debug(diff[s.top()]);
            s.pop();
        }
        if (!s.size()) {
            s.push(i);        
            continue;
        }

        ans[i] = s.top();
        s.push(i);
    }
    forn(i, 0, n) cout << (ans[i] % n) + 1 << " \n"[i==n*2-1];

    return 0;
}