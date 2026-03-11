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

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout << x << " ";;cout << ln})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

set<char> vogais = {'a', 'e', 'i', 'o', 'u', 'y'};

int main() {
    _;
    string a, b; cin >> a >> b;
    
    ll ia = 0, ib = 0;
    while (ia < a.size() && ib < b.size()) {
        if (a[ia] >= 'A' && a[ia] <= 'Z') a[ia] += ('a' - 'A');
        if (b[ib] >= 'A' && b[ib] <= 'Z') b[ib] += ('a' - 'A');

        if (a[ia] == b[ib]) {
            ia++;
            ib++;
            continue;
        }

        if (vogais.count(b[ib])) {
            ib++;
            continue;
        }

        debug(ia);
        debug(ib);        
        cout << "Different" << ln;
        return 0;
    }

    while (ib < b.size()) {
        if (b[ib] >= 'A' && b[ib] <= 'Z') b[ib] += ('a' - 'A');
        if (vogais.count(b[ib])) {
            ib++;
        } else {
            break;
        }
    }

            debug(ia);
        debug(ib);        

    if (ia == a.size() && ib == b.size()) {
        cout << "Same" << ln;
    } else {
        cout << "Different" << ln;
    }

    return 0;
}