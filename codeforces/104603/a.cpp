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

int main() {
    _;
    ll n, m; cin >> n >> m;
    v64 vec(n);
    v64 mods(m);

    forn(i,0,n) cin >> vec[i];
    forn(i,0,m) cin >> mods[i];


    v64 imp;
    ll curr = mods[0];
    
    imp.push_back(curr);

    forn(i,1,m){
        if(mods[i] > curr) continue;
        imp.push_back(mods[i]);
        curr = mods[i];
    }
    
    sort(imp.begin(), imp.end());
    debugv(imp);
    v64 resp(n);


    forn(i,0,n){
        ll val = vec[i];
        while(val >= imp[0]){
            auto it = prev(upper_bound(imp.begin(), imp.end(), val)); 
            ll k = *it;
            debug(val);
            debug(k);
            val %= k;
        }
        resp[i] = val; 
    }

    forn(i,0,n) cout << resp[i] << " \n"[i == n-1];
    return 0;
} 