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
const ll MAXD = 1'000'010;
v64 primes;
vector<bool> is_comp(MAXD, false);

void sieve(ll n){
    forn(i,2,n){
        if(!is_comp[i]) primes.push_back(i);

        forn(j,0,primes.size()){
            if(i*primes[j] > n) break;
            is_comp[i*primes[j]] = true;

            if(i % primes[j] == 0){
                break;
            }
        }
    }
}

vector<v64> divisors(MAXD+1);

void get_divisors(){
    forn(i,2,MAXD){
        if(is_comp[i]) continue;
        for(ll j = i; j <= MAXD; j += i){
            divisors[j].push_back(i);
        }
    }
}

int main(){
    _;
    sieve(MAXD-1);
    get_divisors();
    ll n; cin >> n;

    multiset<ll> s;
    
    vector<bool> state(MAXD, false);
    v64 resp(MAXD, 0);

    forn(i,0,n){
        ll d; cin >> d;
        ll change = 1;

        if(state[d]){
            state[d] = 0;
            change = -1;
        }else{
            state[d] = 1;
        }

        for(ll p: divisors[d]){
            ll oldv = resp[p]; 
            resp[p] += change;
            ll newv = resp[p];

            if(oldv != 0){
                s.erase(s.find(oldv));
            }

            if(newv != 0){
                s.insert(newv);
            }
        }

        if(s.empty()){
            cout << 0 << ln;
        }else{
            cout << *s.rbegin() << ln;
        }
    }
    return 0;  
}