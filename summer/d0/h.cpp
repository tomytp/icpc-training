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
    vector<bool> is_one(7);
    v64 g1, g2;
    forn(i, 0, 7) {
        cout << "? " << (char)('a'+i) << (char)('a'+i) << endl;
        ll x; cin >> x;
        if (x) g1.push_back(i), is_one[i] = true;
        else g2.push_back(i);
    }

    v64 up(7);
    forn(i, 0, 7) {
        forn(j, i+1, 7) {
            if (is_one[i] && is_one[j]) {
                // caso 1
                cout << "? " << (char)('a'+i) << (char)('a'+i) << (char)('a'+j) << (char)('a'+j) << endl;
                ll x; cin >> x;
                if (x) up[i]++;
                else up[j]++;
            }
            if (!is_one[i] && !is_one[j]) {
                cout << "? " << (char)('a'+i) << (char)('a'+j) << endl;
                // caso 5
                ll x; cin >> x;
                if (x) up[i]++;
                else up[j]++;
            }
        }
    }
    forn(i, 0, 7) {
        up[i] *= 2;
        if (!is_one[i]) up[i]++;
    }
    
    cout << "! ";
    for(ll j = 6; j>=0; j--) {
        forn(i, 0, 7) {
            if(up[i] == j) {
                cout << (char)('a'+i);
            }
        }
    }
    cout << endl;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}