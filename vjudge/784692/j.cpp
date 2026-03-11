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
    v64 vec(n);
    forn(i,0,n){
        cin >> vec[i];
        vec[i]--;
    }

    v64 inv(n);
    forn(i,0,n){
        inv[vec[i]] = i;
        inv.push_back(-1);
    }

    string resp(n,' ');
    char c = 'a';
    resp[vec[0]] = c;

    forn(i,1,n){
        ll prev_next = inv[vec[i-1] + 1];
        ll curr_next = inv[vec[i] + 1];

        if(prev_next > curr_next) c++;
        
        if(c > 'z'){
            cout << -1 << ln;
            return 0;
        }

        resp[vec[i]] = c;
    }

    cout << resp << ln;
    return 0;
}