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

const ll maxv = 100000;

vector<bool> is_prime(maxv);
vector<ll> factor(maxv);

void solve(multiset<ll> &c){
    cout << c.size() << ln;
    for(auto x : c){
        cout << x << " ";
    }
    cout << ln;
}


int main(){
    _;
    ll n; cin >> n;
    map<ll,ll> freq;
    multiset<ll> c;

    forn(i,0,n){
        ll aux; cin >> aux;
        freq[aux]++;
    }

    if(freq[7487] < 1){
        cout << 0 << ln;
        return 0;
    }
    c.insert(7487);

    if(freq[8*269]>=1){
        c.insert(8*269);
        solve(c);
        return 0;
    }

    if(freq[4*269] >= 1 and freq[2]>= 1){
        c.insert(2);
        c.insert(4*269);
        solve(c);
        return 0;
    }

    if(freq[2*269] >= 1){
        if(freq[4]>=1){
            c.insert(4);
            c.insert(2*269);
            solve(c);
            return 0;
        }

        if(freq[2]>= 2){
            c.insert(2);
            c.insert(2);
            c.insert(2*269);
            solve(c);
            return 0;
        }
    }

    if(freq[269]>=1){
        if(freq[8]>=1){
            c.insert(269);
            c.insert(8);
            solve(c);
            return 0;
        }

        if(freq[4]>= 1 and freq[2] >= 1){
            c.insert(269);
            c.insert(4);
            c.insert(2);
            solve(c);
            return 0;
        }

        if(freq[2]>= 3){
            c.insert(269);
            c.insert(2);
            c.insert(2);
            c.insert(2);
            solve(c);
            return 0;
        }
    }

    cout << 0 << ln;
    return 0;
    return 0;
}