#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 1'000'000'000;
// const ll MAX = 10;


ll xp(ll a, ll b, ll c, ll d) {
    return (b-a+1)*(d-c+1);
};

ll ask(ll a, ll b, ll c, ll d){
    debug(xp(a, b, c, d));
    cout << "? " << a << " " << c << " " << b << " " << d << endl;
    ll x; cin >> x;
    return x; 
}

p64 tenta_esq(ll l, ll r, ll to){
    if (to == 0) return {-INF, -INF};
    if(l == r){
        if(to == 1) return {l,-INF};
        if(to == 2) return {l, l};
    }

    ll mid = (l+r)/2;

    ll resp = ask(l, mid, 1, MAX);
    ll diff = resp - xp(l, mid, 1, MAX);
    
    if (diff == to) return tenta_esq(l, mid, to);
    if (diff == 0) return tenta_esq(mid+1, r, to);

    if (to == 2) {
        if (diff == 1) {
            p64 a, b;
            a = tenta_esq(l, mid, 1);
            b = tenta_esq(mid+1, r, 1);
            return {a.first, b.first};
        }
    }
    assert(false);
    return {-INF,-INF};
}

p64 tenta_dir(ll l, ll r, ll to){
    if (to == 0) return {-INF, -INF};
    if(l == r){
        if(to == 1) return {l,-INF};
        if(to == 2) return {l, l};
    }
    
    ll mid = (l+r)/2;

    ll resp = ask(1, MAX, l, mid);
    ll diff = resp - xp(1, MAX, l, mid);
    
    if (diff == to) return tenta_dir(l, mid, to);
    if (diff == 0) return tenta_dir(mid+1, r, to);

    if (to == 2) {
        if (diff == 1) {
            p64 a, b;
            a = tenta_dir(l, mid, 1);
            b = tenta_dir(mid+1, r, 1);
            return {a.first, b.first};
        }
    }
    assert(false);
    return {-INF,-INF};
}

int main(){
    _;
    
    p64 p = tenta_esq(1,MAX, 2);
    
    p64 q = tenta_dir(1,MAX, 2);
    
    trace(
        cout << p.first << "  " << p.second << ln;
        cout << q.first << "  " << q.second << ln;
    );

    ll p1q1 = ask(p.first, p.first, q.first, q.first);
    // ll p1q2 = ask(p.first, p.first, q.second, q.second);

    // ll p2q1 = ask(p.second, p.second, q.first, q.first);
    ll p2q2 = ask(p.second, p.second, q.second, q.second);

    cout << "! ";

    if(p1q1 == 2){
        cout << p.first << " " << q.first << " ";    
    }else{
        cout << p.first << " " << q.second << " ";    
    }

    if(p2q2 == 2){
        cout << p.second << " " << q.second << " ";    
    }else{
        cout << p.second << " " << q.first << " ";    
    }
    cout << ln;
    return 0;
}