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

ll st(string& s) {
    ll pow = 1;
    ll ans = 0;
    for (ll i = (ll)s.size() - 1; i >= 0; i--) {
        ans += pow * ((ll)(s[i]-'0'));
        pow *= 10;
    }
    return ans;
}

int main(){
    _;
    ll n; cin >> n;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];

    bool done = false;
    forn(i, 0, n-1) {
        ll old = -1;
        if (v[i+1][0] != 1) old = v[i+1][0], v[i+1][0] = '1';
        if (st(v[i]) > st(v[i+1])) {
            done = true;
            debug(st(v[i]));
            debug(st(v[i+1]));
            break;
        }
        if (old != -1) v[i+1][0] = old;

        old = -1;
        if (v[i][0] != 9) old = v[i][0], v[i][0] = '9';
        if (st(v[i]) > st(v[i+1])) {
            debug(v[i]);
            debug(v[i+1]);
            done = true;
            break;
        }
        if (old != -1) v[i][0] = old;

        if (v[i+1].size() == 1 && v[i] != "0") {
            v[i+1] = "0";
            done = true;
        }
    }

    if (done) {
        forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    } else {
        cout << "impossible" << ln;
    }



    return 0;
}