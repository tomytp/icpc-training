#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const ll MAX = 100'004;

vector<v64> divisor(MAX);

void prepara(){
    forn(i, 1, MAX)
    for(ll j = 0; j<MAX; j+=i) divisor[j].push_back(i);
}

bool bs(ll x, ll q, ll l, ll r, ll s){
    debug(x);
    debug(q);
    debug(l);
    debug(r);
    while(l <= r){
        ll m = (l+r)/2;
        debug(m);
        ll sum = (m+1)*x + (m*(m+1)/2)*q;
        if(s == sum) return true;
        if(s > sum) l = m+1;
        if(s < sum) r = m-1;
    }
    return false;
}

int main() {
    _; ll a, s, l, r; cin >> a >> s >> l >> r;

    prepara();
    ll counter = 0;
    forn(x, l, a+1){
        for(auto q : divisor[a-x]){
            counter += bs(x, q, max((a-x)/q,1ll), (r-x)/q, s);
        }
    }
    counter += (s == a); 

    cout << counter << ln;
    return 0;
}