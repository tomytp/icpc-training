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

string t1(string s, ll ca, ll cb, ll ba, ll bc, ll bca) {
    forn(i, 0, s.size()) {
        if (s[i] == 'c') {
            if (ca) {
                s[i] = 'a';
                ca--;
            } else if (bca) {
                s[i] = 'a';
                bca--;
            } else if (cb && ba) {
                s[i] = 'a';
                cb--;
                ba--;
            } else if (cb) {
                s[i] = 'b';
                cb--;
            }
        }

        if (s[i] == 'b') {
            if (ba) {
                s[i] = 'a';
                ba--;
            } else if (bca) {
                s[i] = 'a';
                bca--;
            }
        }
    }
    return s;
}

string t2(string s, ll ca, ll cb, ll ba, ll bc, ll bca) {
    forn(i, 0, s.size()) {
        if (s[i] == 'c') {
            if (ca) {
                s[i] = 'a';
                ca--;
            } else if (cb && ba) {
                s[i] = 'a';
                cb--;
                ba--;
            } else if (bca) {
                s[i] = 'a';
                bca--;
            } else if (cb) {
                s[i] = 'b';
                cb--;
            }
        }

        if (s[i] == 'b') {
            if (ba) {
                s[i] = 'a';
                ba--;
            } else if (bca) {
                s[i] = 'a';
                bca--;
            }
        }
    }
    return s;
}


void solve() {
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    set<ll> ca, cb, ba, bc;
    
    forn(i, 0, q) {
        char u, v; cin >> u >> v;
        if (u == v) continue;
        if (u == 'a') continue;
        if (u == 'b') {
            if (v == 'a') ba.insert(i);
            else bc.insert(i);
        }
        else {
            if (v == 'b') cb.insert(i);
            else ca.insert(i);
        }
    }

    forn(i, 0, s.size()) {

                if (s[i] == 'b') {
            if (!ba.empty()) {
                s[i] = 'a';
                ba.erase(ba.begin());
            }
            else if (!bc.empty()) {
                auto it1 = bc.begin();
                auto it2 = ca.upper_bound(*it1);
                if (it2 != ca.end()) {
                    s[i] = 'a';
                    bc.erase(it1);
                    ca.erase(it2);
                }
            }
        }
        
        if (s[i] == 'c') {
            if (!ca.empty()) {
                s[i] = 'a';
                ca.erase(ca.begin());
            }
            else if (!cb.empty()) {
                auto it1 = cb.begin();
                auto it2 = ba.upper_bound(*it1);
                if (it2 != ba.end()) {
                    s[i] = 'a';
                    cb.erase(it1);
                    ba.erase(it2);
                } else {
                    s[i] = 'b';
                    cb.erase(it1);
                }
            }
        }



    }
    cout << s << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}