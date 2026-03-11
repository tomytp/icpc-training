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
    _; ll n; cin >> n;
    vector<v64> pop(n, v64(n));
    forn(i, 0, n){
        forn(j, 0, n){
            cin >> pop[i][j];
        }
    }

    trace(
    forn(i, 0, n){
        forn(j, 0, n){
            cout << pop[i][j] << " ";
        }
        cout << ln;
    });
 
    ll best_pop = 0;
    vector<p64> match;
    for(ll curr = n-1; curr >= 1; curr--){
        debug(curr);
        ll op, pop_op = 0;
        forn(i, 0, curr){
            debug(i);
            debug(pop[curr][i]);
            if(pop[curr][i] >= pop_op){
                pop_op = pop[curr][i];
                op = i;
            }
        }

        match.push_back({curr+1, op+1});
        best_pop += pop_op;
        forn(i, 0, n-1){
            pop[op][i] = max(pop[op][i], pop[curr][i]);
            pop[i][op] = max(pop[i][op], pop[i][curr]);
        }
    }

    cout << best_pop << ln;
    forn(i, 0, sz(match)) cout << match[i].first << " " << match[i].second << ln;

    return 0;
} 