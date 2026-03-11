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

template<std::size_t N>
bool operator<(const std::bitset<N>& x, const std::bitset<N>& y)
{
    for (int i = N-1; i >= 0; i--) {
        if (x[i] && !y[i]) return false;
        if (!x[i] && y[i]) return true;
    }
    return false;
}



void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    bitset<5000> b, mx;
    ll fz = -1;
    forn(i, 0, sz(s)) {
        b[i] = (s[i] == '1');
        if (s[i] == '0') fz = i;
    }
    if (fz == -1) {
        cout << 1 << " " << sz(s) << " 1 1\n";
        return;
    }

    ll tam = fz+1;
    ll l = -1, r = -1; 
    
    for (ll i = sz(s); i >= tam; i--) {
        bitset<5000> nw;
        forn(j, 0, tam) {
            nw[j] = b[i-tam+j];
        }
        if (mx < (nw^b)) {
            mx = (nw^b);
            ll revl = i - tam;
            ll revr = i - 1;
            
            l = sz(s) - revr;
            r = sz(s) - revl;
        }
    }
    cout << l << " " << r << " " << 1 << " " << sz(s) << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}