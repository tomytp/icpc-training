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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

ll amt = 0;
ll ask(ll t1, ll t2, ll x, ll y, string resp){
    auto resp2 = resp;
    x--; y--;
    reverse(resp2.begin(), resp2.end());
    
    string s1, s2;
    if (t1 == 1) s1 = resp;
    else s1 = resp2;

    if (t2 == 1) s2 = resp;
    else s2 = resp2;

    ll cnt = 0;
    forn(i, 0, sz(s1)) {
        if (x + i >= sz(s1) || y + i >= sz(s1)) break;
        if (s1[x+i] == s2[y+i]) cnt++;
        else break;
    }

    return cnt;
}

string gen() {
    ll n = uniform(1, 100000);
    string s(n, ' ');
    forn(i, 0, n) s[i] = (char) (uniform(0, 25) + 'a');
    return s;
}

ll solve(string resp){   
    amt = 0;
    ll n = sz(resp);
    ll cnt = 0;
    ll curr = n;
    ll x = ask(1,2,1,1, resp);

    if(x == n){
        return 1;
    }

    while(curr%2 == 0){
        cnt++;
        x = ask(1,1,(curr/2) + 1, 1, resp);
        if(x < curr/2) break;
        curr /= 2;
    }
    
    if(curr%2 == 0) cnt++;
    return (cnt%2);
}

bool palin(string resp) {
    auto r = resp;
    reverse(r.begin(), r.end());
    return r == resp;
}

ll play(string resp) {
    ll curr = 1;
    while (true) {
        if (palin(resp)) return curr;
        if (sz(resp) % 2 == 1) return (curr+1) % 2;
        string t1, t2;
        forn(i, 0, sz(resp)/ 2) {
            t1.push_back(resp[i]);
            t2.push_back(resp[i + sz(resp)/2]);
        } 
        if (t1 != t2) return (curr+1) %2;
        resp = t1;
        curr = (curr+1) % 2;
    }
    return curr;
}

int main(){
    _;

    ll c = 0;
    while (true) {
        c++;
        cout << c << endl;
        string resp = gen();
        ll ans = solve(resp);
        ll p = play(resp);
        if (ans != p) {
            cout << ans << " " << p << ln;
            cout << resp << ln;
            break;
        }
    }

    return 0;
}