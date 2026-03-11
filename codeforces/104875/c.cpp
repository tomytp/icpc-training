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

int main() {
    _;
    ll s; cin >> s;
    ld l = 0;
    ld r = 40'000;
    ld ans = r;

    forn(iter, 0, 4000){
        ld mid = (l+r)/2;
        ll amt = calc(mid);
        // trace(
        //     cout << l << " " << mid << " " << r << ln;
        // );
        // debug(amt);
        // debug(s);
        if(amt > s){
            ans = mid;
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << fixed << setprecision(10) << " " << ans << ln; 
    return 0;
} 