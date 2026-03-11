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

const ll INF = 0x3f3f3f3fll;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main(){
    _;
    ll n = uniform(50, 200);
    cout << n << ln;
    set<p64> st;
    ll i = 0;
    while (st.size() < n-4) {
        st.emplace(uniform(0, 100000), uniform(0, 100000));
        i++;
    }

    for (auto [a, b] : st) {
        cout << a << " " << b << ln;
    }

    cout << -INF + 1 << " " << -INF << ln;
    cout << INF  + 4 << " " << -INF << ln;
    cout << -INF + 9 << " " << INF << ln;
    cout << INF + 16 << " " << INF << ln;
    return 0;
} 