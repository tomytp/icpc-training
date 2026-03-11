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
const ll I = 0x3f3f3f3f3f3f3f3fll;

const ll N = 1'000'000'000;
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
    sieve();

    set<ll> c;
    // c.insert(0);
    c.insert(4);
    c.insert(6);
    // c.insert(8);
    c.insert(9);
    //         0 1 2 3 4 5 6 7 8 9
    v64 lim = {4,0,0,0,1,0,3,0,0,1};

    for(auto p : pr){
        if(p%100 != 49) continue;
        ll test_p = p;
        bool deu_merda = false;
        v64 freq(10);
        ll last = -1;
        while(test_p > 0){
            freq[test_p%10]++;
            last = test_p%10;
            test_p/=10;

        }
        if(last != 9) deu_merda = true;
        forn(i,0,10) if(freq[i] > lim[i]) deu_merda = true;        
        if(!deu_merda) cout << p << " ";
    }
    cout << "N = " << N << ln;
    return 0;
}