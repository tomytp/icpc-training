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

void solve(ll a, ll b){
    if(b-a!= 1){
        cout << "impossible" << ln;
        return;
    }

    cout << a+1 << " " << a << ln;
    forn(i, 0, a) cout << i+2 << " " << 1 << ln;
}

int main() {
    _;
    ll a, b; char c;
    cin >> a >> c >> b;

    ll d = gcd(a, b);
    a /= d;
    b/= d;

    if(a < b){
        solve(a, b);
        return 0;
    }
    if(a == b){
        cout << 3 << " " << 2 << ln;
        cout << 2 << " " << 1 << ln;
        cout << 2 << " " << 3 << ln;
        return 0;
    }
    if(b == 1){
        ll k = (a*a+a-2)/2;
        cout << a+k+2 << " " << a + k +1 << ln;
        forn(i, 0, a+1){
            cout << i+1 << " " << i+2 << ln;
        }
        forn(i, 0, k){
            cout << i+a+3 << " " << a+1 << ln;
        }
        return 0;
    }
    
    ll k = (a+b-1)/b;
    ll vk, vk_menos_1;
    ll s = (k+1)*a - (b*k*(k+1))/2;
    ll ck = k*b-a, ck_menos_1 = a - (k-1)*b;

    forn(i, 0, ck){
        if((s + i*ck_menos_1)%ck == 0){
            vk_menos_1 = i;
            break;
        }
    }

    vk = (s + vk_menos_1*ck_menos_1)/ck;

    cout << k+vk+vk_menos_1+1 << " " << k+vk+vk_menos_1 << ln;

    forn(i, 0, k) cout << i+1 << " " << i + 2 << ln;
    forn(i, 0, vk) cout << i + k + 2 << " " << k << ln;
    forn(i, 0, vk_menos_1) cout << i + vk + k + 2 << " " << k-1 << ln;

    return 0;
}