#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"
#define sz(x) ((ll) x.size())

#if defined(DEBUG)
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

    v64 x(n); v64 y(n); // P e S
    v64 p(n), s(n);

    set<ll> xset, yset;

    forn(i,0,n){
        cin >> x[i] >> y[i];
        if(x[i]%2 == 0) xset.insert(x[i]);
        if(y[i]%2 == 0) yset.insert(y[i]);
    }

    if(n == 1){
        if(x[0] == 2 && y[0] == 2){
            cout << "NO" << ln;
            return 0;
        }
        cout << "YES" << ln;
        cout << 1 << " " << 1 << ln;
        return 0;
    }

    if(xset.size() == n && yset.size() == n){
        ll idx = 0;
        for(; idx < n; idx++) if(y[idx] == 2) break;
        forn(i,0,n){
            p[i] = x[idx]/2;
            s[i] = i+1;
        }

        if(x[idx]/2 % 2 == 0) p[0] = 1;
        else p[0] = 2;

    }else if(xset.size() < n){
        ll val = 2;
        for(ll par: xset){
            if(par != val) break;
            val += 2;
        }
        forn(i,0,n){
            p[i] = val/2;
            s[i] = i+1;
        }
    }else if(yset.size() < n){
        ll val = 2;
        for(ll par: yset){
            if(par != val) break;
            val += 2;
        }
        forn(i,0,n){
            p[i] = i+1;
            s[i] = val/2;
        }
    }else{
        assert(false);
    }

    cout << "YES" << ln;
    forn(i,0,n){
        cout << p[i] << " " << s[i] << ln;
    }
    
    return 0;
}