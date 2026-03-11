#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;

    ll n; cin >> n;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];

    set<char> st;
    forn(i, 0, n) {
        st.insert(v[i][0]);
    }

    forn(i, 0, n) {
        bool found = true;
        for (auto c : v[i]) {
            if (!st.count(c)) {
                found = false;
                break;
            }
        }

        if (!found) continue;
        cout << "Y" << ln;
        return 0;
    }
    cout << "N" << ln;
    return 0;
}