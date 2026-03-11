#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld ep =  1e-15l;

int main() {
    _;
    ll n, velo; cin >> n >> velo;
    ld prio = 0;
    ld nprio = 0;

    forn(i,0,n){
        char c; ll x;
        cin >> c >> x;

        if(c == 'P'){
            prio += x;
        }else{
            nprio += x;
        }
    }

    ld vprio = 0.75*velo;
    ld vnprio = 0.25*velo;

    ld tprio = prio/vprio;
    ld tnprio = nprio/vnprio;

    ld t1 = min(tprio, tnprio);
    prio -= t1*vprio;
    nprio -= t1*vnprio;
    
    if(prio < ep){
        swap(prio, nprio);
    }

    ld t2 = prio/velo;
    cout << fixed << setprecision(20) << t1+t2 << ln;
    return 0;
}