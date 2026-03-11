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

p64 func(ll b, ll d){
    ll guess = 1;
    ll exp = 0;
    for(exp = 1; exp <= 1000; exp++){
        guess = (guess*b)%d;
        if(guess == 0) break;
    }

    if(guess == 0) return {2,exp};
    if((b-1)%d == 0) return {3,-1};
    if((b+1)%d == 0) return {11,-1};
    return {7,-1};
}

int main() {
    _;
    ll b,d;
    cin >> b >> d;

    bool t7 = false;
    
    p64 resp = func(b,d);

    if(resp.first != 7){
        if(resp.first == 2){
            cout << "2-type" << ln;
            cout << resp.second << ln;
            return 0;
        }

        if(resp.first == 3){
            cout << "3-type" << ln;
            return 0;
        }

        if(resp.first == 11){
            cout << "11-type" << ln;
            return 0;
        }
    }
    
    forn(p,2,101){
        if(d%p != 0) continue;
        ll pot = p; 
        while(d%(pot*p) == 0) pot *= p;
        d /= pot;
        p64 dupla = func(b,pot);
        debug(dupla.first);
        debug(dupla.second); 
        debug(pot);
        if(dupla.first == 7) t7 = true;
    }
    
    if(t7){
        cout << "7-type" << ln;
    }else{
        cout << "6-type" << ln;
    }
    
    

    return 0;
}
