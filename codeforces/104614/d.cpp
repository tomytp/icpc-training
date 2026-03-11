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
    string s;
    cin >> s;
    ll n = s.size(); 
    ll q; cin >> q;
    v64 t(n),a(n),c(n),g(n);

    forn(i,0,n){
        if (i) {
            t[i] = t[i-1];
            a[i] = a[i-1];
            c[i] = c[i-1];
            g[i] = g[i-1];
        }

        if(s[i] == 'T') t[i]++; 
        if(s[i] == 'A') a[i]++; 
        if(s[i] == 'C') c[i]++; 
        if(s[i] == 'G') g[i]++; 
    }


    forn(i,0,q){
        ll l, r;
        cin >> l >> r;
        l--; r--;
        ll tq, aq, cq, gq;

        debug(l);
        debug(r);
        tq = t[r] - (l == 0 ? 0 : t[l-1]);
        aq = a[r] - (l == 0 ? 0 : a[l-1]);
        cq = c[r] - (l == 0 ? 0 : c[l-1]);
        gq = g[r] - (l == 0 ? 0 : g[l-1]); 

        vector<pair<ll, string>> aux = {{aq, "dA"}, {tq, "cT"}, {gq, "bG"}, {cq, "aC"}};
        stable_sort(aux.rbegin(), aux.rend());

        forn(j,0,4) cout << aux[j].second[1];
        cout << ln;
    }
    return 0;
}