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

#define debugv(v) trace({cout << #v": "; for (auto u : v) cout<< u << " "; cout << ln;})
#define debugp(v) trace({cout << #v": "; for (auto u : v) cout<< u.first << ":" << u.second << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll x, y, n, m, k, s;
    cin >> x >> y >> n >> m >> k >> s;
    set<ll> allow;

    forn(i,0,n){
        ll aux; cin >> aux;
        allow.insert(aux);
    }

    vector<v64> divs(x+1);
    forn(i,2,x+1){
        if(!allow.count(i)) continue;
        for(ll j = i; j < x+1; j += i){
            divs[j].push_back(i);
        }
    }

    v64 sub(m);
    forn(i,0,m) cin >> sub[i];
    sort(sub.begin(), sub.end());

    set<p64> alive;
    set<p64> next;
    
    if(s > 50){ 
        cout << "No" << ln;
        return;
    }

    alive.insert({x,0});

    forn(t,0,s-1){
        debugp(alive);
        for(auto [valor, cnt]: alive){
            if(valor <= y) continue;
            for(ll d: divs[valor]){
                next.insert({valor/d, cnt});
            }
            
            for(ll su: sub){ 
                if(cnt + 1 > k) break;
                if(valor <= su) break;
                next.insert({valor - su, cnt + 1});
            }
        }
        alive.clear();
        swap(alive, next); 
    }
    debugp(alive);

    for(auto [valor, cnt]: alive){ 
        if(valor <= y){
            cout << "Yes" << ln;
            return;
        }        
        if(cnt == k && sz(divs[valor]) == 0){
            cout << "Yes" << ln;
            return;
        }
        if(sz(divs[valor]) == 0 && valor <= sub[0]){
            cout << "Yes" << ln;
            return;
        }
    }
    cout << "No" << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}