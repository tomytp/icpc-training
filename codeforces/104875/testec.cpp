#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld ep = 0.000'000'001;

ll calc(ld r){

    ld r2 = r*r;

    ll x = 1;
    ll resp = 0;
    while(x < r+ep){
        ll y = 0;
        if(r2 - x*x > 0) y = (ll)(sqrt(r2 - x*x) + ep);

        resp += y;
        x++;
    }
    debug(resp);
    resp *= 4;
    return resp;
}

bool dentro(ll x, ll y, ld r){
    return (x*x + y*y <= r*r + ep);
}

ll calc_burro(ld r){
    ll bound = (ll)(r+2);
    ll resp = 0;
    forn(x,-bound, bound+1)
    forn(y,-bound, bound+1){
        bool valid = true;
        if(!dentro(x,y,r)) valid = false;
        if(!dentro(x,y-1,r)) valid = false;
        if(!dentro(x-1,y,r)) valid = false;
        if(!dentro(x-1,y-1,r)) valid = false;
        if(valid) resp++;
    }
    return resp;
}

int main() {
    _;

    ll cnt = 0;

    for(ld r = 1; r < 10'000; r += 0.01){
        if(calc_burro(r) != calc(r)) cout << r << ln;
        
        if(cnt%100 == 0){
            cout << cnt << ln;
        }
        cnt++;
    }
    return 0; 
} 