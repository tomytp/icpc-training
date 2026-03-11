#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

int main() {
    _;
    ll a, b;
    cin >> a >> b;

    ll fizz = 0;
    ll buzz = 0;

    forn(i,a,b+1){
        string s;
        cin >> s;
        if(s == "Fizz"){
            fizz = gcd(fizz, i);
        }else if(s == "Buzz"){
            buzz = gcd(buzz, i);
        }else if(s == "FizzBuzz"){
            fizz = gcd(fizz, i);
            buzz = gcd(buzz, i);
        }
    }

    if(fizz == 0) fizz = 1'000'000;
    if(buzz == 0) buzz = 1'000'000;

    cout << fizz << " " << buzz << ln;
    return 0;
}