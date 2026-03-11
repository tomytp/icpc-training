#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef vector<ld> vld;

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

int main() {
    _;
    ll n, k; cin >> n >> k;

    vld p(n);
    forn(i,0,n) cin >> p[i];

    sort(p.rbegin(), p.rend());

    vld d(n+1);
    d[0] = 1;
    ld best= 0 ;
    forn(l,0,n){
        ll target = (l+k+1)/2;
        ld sum = 0;
        forn(j,target, n+1) sum += d[j];
        best = max(sum ,best);

        for(ll i = n; i>0; i--){
            d[i] = (1-p[l])*d[i] + p[l]*d[i-1];
        }
        d[0] *= (1-p[l]);
    }
    ll target = (n+k+1)/2;
    ld sum = 0;
    forn(j,target, n+1) sum += d[j];
    best = max(sum ,best);
    cout << best << ln;
    // debugv(d);
    return 0;
}
