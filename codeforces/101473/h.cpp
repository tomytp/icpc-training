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
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1'000'000;

vector<v64> mult(vector<v64>& l, vector<v64>& r){
    vector<v64> aux(2, v64(2));

    aux[0][0] = (l[0][0]*r[0][0]+l[0][1]*r[1][0])%MOD;
    aux[0][1] = (l[0][0]*r[0][1]+l[0][1]*r[1][1])%MOD;
    aux[1][0] = (l[1][0]*r[0][0]+l[1][1]*r[1][0])%MOD;
    aux[1][1] = (l[1][0]*r[0][1]+l[1][1]*r[1][1])%MOD;
    return aux;
}

int main() {
    _;
    ll n, k, l;
    cin >> n >> k >> l;
    k %= MOD;
    l %= MOD;

    vector<v64> b = {{k, l},{1,0}};
    vector<v64> pot = b;
    vector<v64> resp = {{k, 0},{1,0}};

    ll exp = n/5 - 1;

    while(exp){
        debugv(resp[0]);
        debugv(resp[1]);
        debugv(pot[0]);
        debugv(pot[1]);
        trace(cout << ln;);

        if(exp&1) resp = mult(pot, resp);
        pot = mult(pot, pot);
        exp /= 2;
        
    }

    ll ans = resp[0][0]; 
    v64 aux(6);
    ll cnt = 0;
    while(ans > 0){
        aux[5-cnt] = ans%10;
        ans /= 10;
        cnt++;
    }
    forn(i,0,6) cout << aux[i];
    cout << ln;
    return 0;
}