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

// Linear Sieve (prime precomputation)
//
// Computes primes up to N in O(N) using the smallest prime factor (lp).
// pr will contain all primes <= N.
// lp[x] stores the smallest prime dividing x.
//
// complexity: O(N)
// escrito pelo gpt, cuidado

const ll N = 100'010;
v64 lp(N+1), pr;

void sieve(){
    forn(i, 2, N+1) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

int main(){
    _;
    sieve();
    set<ll> primos;
    for(ll p : pr) primos.insert(p);

    ll n; cin >> n;

    v64 perm(n+1);
    ll p1 = n;
    ll p2 = n;
    
    while(p1 >= 0 && p2 >= 0){
        if(primos.count(p1+p2)){
            forn(x, p1, p2+1) perm[x] = p2 + p1 - x;
            p2 = p1-1;
            p1 = p2;
            continue;
        }
        p1--;
    }

    forn(i,1,n+1) cout << i << " " ;; cout << ln;
    forn(i,1,n+1) cout << perm[i] << " ";; cout << ln;
    return 0;
}