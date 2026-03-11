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

    if(n == 1){
        cout << vec[0] << ln;
        return 0;
    }

    v64 resp(n);
    ll l,r;

    auto ans_imp = [&](ll mid){
        v64 v;
        assert(mid != 0);
        assert(mid != n-1);
        ll vl = vec[mid-1];
        ll vm = vec[mid];
        ll vr = vec[mid+1];
        if(vm <= min(vl, vr)) return vm;
        forn(i,mid-1,mid+2) v.push_back(vec[i]);
        sort(v.begin(), v.end());
        return v[1];
    };

    if(n%2 == 0){
        l = n/2 - 1;
        r = n/2;
        resp[0] = max(vec[l], vec[r]);
        resp[1] = max(ans_imp(l), ans_imp(r));
    }else{
        l = r = n/2;
        resp[0] = ans_imp(l);
        resp[1] = max({vec[l-1], vec[l], vec[l+1]});
        l--;r++;
    }


    forn(k, 2, n-1){
        ll curr = resp[k-2];
        if(((n-k) % 2) == 0){
            l--;
            r++;
            curr = max(curr, vec[l]);
            curr = max(curr, vec[r]);
        }else{
            curr = max(curr, ans_imp(l));
            curr = max(curr, ans_imp(r));
        }
        resp[k] = curr;
        debug(curr);
    }

    forn(i,0,n) resp[n-1] = max(resp[n-1], vec[i]);

    // forn(i, 0, n) cout << resp[i] << " \n"[i==n-1];
    forn(i, 0, n) cout << resp[i] << " ";; cout << ln;
    return 0; 

}