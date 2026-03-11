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
    ll n; cin >> n;
    stack<ll> curr, pref;
    forn(i, 0, n) {
        ll q; cin >> q;
        if (q == 1) {
            char c; cin >> c;
            ll currr = 0;
            if (curr.size() > 0) currr = curr.top(); 
            if (c == '(') curr.push(currr+1);
            else curr.push(currr-1);

            ll last_min = 0;
            if (pref.size() > 0) last_min = pref.top();
            pref.push(min(last_min, curr.top()));
        } else {
            pref.pop();
            curr.pop();
        }

        ll last_min = 0;
        if (pref.size() > 0) last_min = pref.top();
        ll currr = 0;
        if (curr.size() > 0) currr = curr.top();
        if (currr == 0 && last_min == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}