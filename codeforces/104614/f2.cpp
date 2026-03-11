#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;
typedef long double ld;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << fixed << setprecision(10) << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = 2*acos((double)0.0);

ll solve(ld &ano_real){
    ll ano_cal = ano_real;
    ld f = ano_real-ano_cal;

    if(f >= 0.5){
        ano_cal++;
        f = ano_cal - ano_real;
    }
    ll n1 = 1/f;
    ano_real = n1*ano_real;
    return n1;
}

int main(){
    _;
    ll r,s, h; cin >> r >> s >> h;
    ld circ = 2*pi*r;
    ld h_ano = circ/s;
    ld ano_real = h_ano/h;

    forn(i, 0, 100) cout << i << " " << fixed << setprecision(20) << ano_real*i - floor(ano_real*i) << ln;
    ll n1 = solve(ano_real);
    cout << ln;
    cout << ln;
    forn(i, 0, 100) cout << i << " " << fixed << setprecision(20) << ano_real*i - floor(ano_real*i) << ln;
    ll n2 = solve(ano_real);
    cout << ln;
    cout << ln;
    forn(i, 0, 100) cout << i << " " << fixed << setprecision(20) << ano_real*i - floor(ano_real*i) << ln;
    ll n3 = solve(ano_real);

    cout << n1 << " " << n2*n1 << " " << n3*n2*n1 << ln;
  
    return 0;
}