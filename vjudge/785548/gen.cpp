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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main() {
    _;
    ll n = uniform(5,6);
    ll m = uniform(n, 8);
    cout << n << " " << m << ln;

    set<p64> s;

    set<ll> s2;
    while(sz(s2) < 2) s2.insert(uniform(1,n));
    v64 v = {*s2.begin(), *prev(s2.end())};

    s.insert({1,v[0]});
    s.insert({v[0],v[1]});
    s.insert({v[1],n});
    
    while(sz(s) < m){
        ll a = uniform(1,n);
        ll b = a;
        while (b == a) b = uniform(1,n);
        
        s.insert({a,b});
    }

    for(auto p: s){
        cout << p.first << " " << p.second << ln;
    }
    
    return 0;
}
