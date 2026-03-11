#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
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
    _; ll n, x; cin >> n >> x;
    v64 a(n);
    ld sum = 0;
    forn(i, 0, n){
        cin >> a[i];
        sum += a[i]*a[i];
    }   
    sum /= n;

    ld c = 1;
    if(sum != 0) c = sqrt((ld)x/sum);
    
    forn(i, 0, n) cout << fixed << setprecision(25) << c*(ld)a[i] << " ";
    cout << ln;
    return 0;
}   