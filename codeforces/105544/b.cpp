#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 pot10(20);

void solve(){
    ll a, b; cin >> a >> b;
    string s1, s2; cin >> s1 >> s2;
    ll n1 = 0, n2 = 0;
    for(ll i = a-1; i>= 0; i--) n1 += pot10[(a-1)-i]*(s1[i]-'0');
    for(ll i = b-1; i>= 0; i--) n2 += pot10[(b-1)-i]*(s2[i]-'0');

    ll num = (pot10[b]-1)*n1 + n2;
    ll den = (pot10[b]-1)*pot10[a];

    cout << num/gcd(num,den) << " " << den/gcd(num,den) << ln;

}

int main() {
    _;
    pot10[0] = 1;
    forn(i, 1, 20) pot10[i] = pot10[i-1]*10;
    
    ll t; cin >> t;
    forn(i, 0, t) solve();
    return 0;
}