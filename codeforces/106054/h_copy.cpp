#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll resp_cand, resp_mis;

ll n; 
v64 vec;
set<ll> s;

ll sq_root(ll target){
    ll l = 0;
    ll r = target;
    ll ans = 0;
    while( l <= r){
        ll mid = (l+r)/2;
        if(mid <= target/mid){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}

void solve2(){
    ll p = sq_root(vec[1]);
    if(p*p == vec[1]){
        resp_cand = vec[1];
        resp_mis = p;
        // cout << vec[1] << " " << p << ln;
    }else{
        resp_cand = vec[1]*vec[1];
        resp_mis = vec[1]*vec[1];
        // cout << vec[1]*vec[1] << " " << vec[1]*vec[1] << ln;
    }
}

bool pot_primo(){
    ll p = vec[1];

    forn(i,2,n) if(vec[i]%p != 0) return false;
    
    p = min(p, vec[2]/p);

    ll pulou = -1;
    ll pot = p;

    forn(i,1,n){
        if(vec[i] != pot){
            if(pulou != -1) return false;
            pulou = pot;
            i--;            
        }
        pot *= p;   
    }

    if(pulou == -1){
        resp_cand = vec.back()*p;
        resp_mis = vec.back()*p;
        // cout << vec.back()*p << " " << vec.back()*p << ln;
    }else{
        resp_cand = vec.back();
        resp_mis = pulou;
        // cout << vec.back() << " " << pulou << ln;
    }

    return true;
}

bool check_cand(){
    ll cand = vec.back();
    
    forn(i,0,n){
        if(cand % vec[i] != 0) return false;
    }

    ll missing = -1;
    ll sq = sq_root(cand);
    if(s.count(sq) == 0) missing = sq;

    forn(i,0,n){
        if(s.count(cand/vec[i]) == 0) missing = cand/vec[i]; 
    }
    resp_cand = cand;
    resp_mis = missing;
    // cout << cand << " " << missing << ln;
    return true;
}

void get_cand(){
    ll curr = vec[0];

    forn(i,1,n){
        ll d = gcd(curr, vec[i]);
        curr /= d;
        curr *= vec[i];
    }
    resp_cand = curr;
    resp_mis  = curr;
    // cout << curr << " " << curr << ln;
}

int solve(){
    _;
    s.clear();
    forn(i,0,n) s.insert(vec[i]);
    sort(vec.begin(), vec.end());

    if(vec[0] != 1){
        resp_cand = vec.back();
        resp_mis = 1;
        // cout << vec.back() << " " << 1 << ln;
        return 0;
    }

    if(n == 1){
        resp_cand = -1;
        resp_mis = -1;
        // cout << '*' << ln;
        return 0;
    }
    if(n == 2){
        solve2();
        return 0;
    }

    if(pot_primo()) return 0;
    if(check_cand()) return 0;

    get_cand();

    return 0;
}

v64 divisores(ll num){
    v64 resp;
    forn(i,1,sq_root(num)+1){
        if(i*i == num) resp.push_back(i);
        else if(num%i == 0){
            resp.push_back(i);
            resp.push_back(num/i);
        }
    }
    return resp;
}

int main(){
    ll targ = 1000000;

    forn(i,2,targ){

        if(i%1000 == 0) cout << i << " ----------\n";
        v64 div = divisores(i);
        ll teoric_cand = i;
        ll teoric_mis = -1;
        n = div.size() - 1;
        forn(j,0,div.size()){
            vec = div;
            teoric_mis = vec[j]; 
            vec.erase(vec.begin()+j);
            solve();

            if(div.size() == 2 && j == 1){
                teoric_cand = -1;
                teoric_mis = -1;
            }

            if(teoric_cand != resp_cand || teoric_mis != resp_mis){
                cout << i << ln;
                forn(t,0,vec.size()) cout << vec[t] << " ";; cout << ln;
            }
        }
    }
}