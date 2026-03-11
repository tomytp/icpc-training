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
const ll SQRMAX = 50;

const ll N = 1986;
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

bool ask(ll d){
    cout << "? " << d << ln;
    bool ans;
    cin >> ans;
    return ans;
}

void solve(){
    bool ans = ask(1);

    ll curr = 1;
    ll ime = 0;
    while(ime < sz(pr) && curr*pr[ime] <= N){
        ans = ask(curr*pr[ime]);
        if(!ans) curr *= pr[ime];
        else ime++;
    }

    cout << "! " << curr << ln;
}

int main(){
    sieve();
    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}