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
    forn(i,0,n) cin >> vec[i];

    auto ans_imp = [&](ll mid){
        v64 v;
        forn(i,mid-1,mid+2) v.push_back(vec[i]);
        sort(v.begin(), v.end());
        return v[2];
    };

    v64 resp(n);
    ll limp,rimp;
    ll lpar,rpar;
    ll curr = 0;
    if(n%2 == 0){
        lpar = n/2 - 1;
        rpar = n/2;
        limp = lpar;
        limp = rpar;
        resp[0] = max(vec[lpar], vec[rpar]);
        resp[1] = max(ans_imp(limp), ans_imp(rimp));
    }else{
        limp = rimp = n/2;
        lpar = limp-1;
        rpar = rimp+1;
        resp[0] = ans_imp(limp);
        resp[0] = max(vec[lpar], vec[rpar]);

    }


    forn(k, 1, n){
        ll curr = resp[k-1];
        if(((n-k) % 2) == 0){
            l--; r++;
            curr = max(curr, vec[l]);
            curr = max(curr, vec[r]);
        }
        resp[k] = curr;
    }

    forn(i, 0, n) cout << resp[i] << " \n"[i==n-1];
    return 0; 

}