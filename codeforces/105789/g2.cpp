#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 1'000'000;

int main() {
    _; ll n; cin >> n;
    vector<ll> v(MAXN, 0);
    string s;

    forn(xxx, 0, n){
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if(c == '|'){ 
            s.push_back('S');
            v[b]+=a;
        }
        if(c == '-'){
            ll worst = INF, best = -INF;
            forn(i, b, b+a){
                worst = min(worst, v[i]);
                best = max(best, v[i]);
            }

            debug(worst);
            debug(best);

            if(worst != best){
                s.push_back('U');
                continue;
            }
            s.push_back('S');
            forn(i, b, b+a) v[i]++;
        }
    }

    cout << s << ln;

    return 0;
}