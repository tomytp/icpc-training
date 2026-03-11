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
const ll MAXN = 22;
const ll MAXM = 20;
mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l,r);
    return uid(rng);
}

int main() {
    _; 
    ll n = uniform(4, MAXN);
    ll k = uniform(1,n-2);
    ll m = uniform(3, min(n*(n-1)/2, MAXM));
    cout << n << " " << m << " " << k << ln;

    set<p64> s;
    s.insert({1,2});
    s.insert({2,3});
    s.insert({3,n});

    while(sz(s) < m){
        ll a = uniform(1,n);
        ll b = a;
        while(a == b) b = uniform(1,n);
        
        s.insert({min(a,b),max(a,b)});
    }

    for(auto p : s) cout << p.first << " " << p.second << ln;

    set<ll> s2;
    while(sz(s2) < k) s2.insert(uniform(2,n-1));

    for(auto x : s2) cout << x << ln;
    return 0;
}