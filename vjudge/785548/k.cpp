#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll N = 10000000;
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

ll nim(ll a){
    ll nimero = 0;

    for(auto p : pr){
        if(p*p > a) break;
        ll exp = 0;
        while(a%p == 0){
            exp++;
            a /= p;
        }
        nimero ^= exp;
    }

    if(a > 1) nimero ^= 1;
    debug(nimero);
    return nimero;
}

int main() {
    _; sieve();
    ll n; cin >> n;
    ll resp = 0;
    forn(i, 0, n){
        ll a; cin >> a;
        resp ^= nim(a);
    }

    if(resp > 0){
        cout << "Mojtaba" << ln;
    } else {
        cout << "Arpa" << ln;
    }
    
    return 0;
}
