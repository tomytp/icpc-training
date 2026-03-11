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
const ll MAXN = 100'000'000;

int main(){
    _;
    ll n; cin >> n;
    string s; cin >> s;

    vector<ll> first_ind(MAXN, INF);
    bitset<26> curr = 0;

    ll best = 0;

    first_ind[curr.to_ullong()] = -1;
    forn(i, 0, n){
        ll aux = s[i] - 'a', curr_best = 0;
        curr = curr.flip(aux);

        if(first_ind[curr.to_ullong()] == INF) first_ind[curr.to_ullong()] = i;
        else curr_best = max(curr_best, i - first_ind[curr.to_ullong()]);

        debug(curr.to_string());

        forn(j, 0, 26){
            auto bs_aux = curr;
            bs_aux.flip(j); 
            debug(bs_aux.to_string());
            
            if(first_ind[curr.to_ullong()] != INF) curr_best = max(curr_best, i - first_ind[bs_aux.to_ullong()]);
        }

        best = max(best, curr_best);
        // cout << curr_best << ln;
    }

    cout << best << ln;
    return 0;
}