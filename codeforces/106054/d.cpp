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

int main(){
    _;
    ll m, n; cin >> m >> n;
    ll tot = n+m;
    v64 winner(tot), nxt(tot, -1);
    vector<pair<string, string>> strs(tot);
    

    ll a = 0, b = 0;
    map<string, v64> idxs_by;
    forn(i, 0, tot) {
        ll v, w; 
        string p, q;
        cin >> v >> p >> w >> q;
        if (p == q) {
            if (v > w) winner[i] = 1, a++;
            else winner[i] = 2, b++;
            nxt[i] = i;
        } else {
            if (i == 0 || winner[i-1] == 1) {
                winner[i] = 1, a++;
            } else {
                winner[i] = 2, b++;
            }
        }
        idxs_by[p].push_back(i);
        if (q != p) idxs_by[q].push_back(i);
        strs[i] = {p, q}; 
    }

    if(nxt[tot-1] == -1) nxt[tot-1] = tot;
    for(ll i = tot-2; i >= 0; i--){
        if(nxt[i] == i) continue;
        nxt[i] = nxt[i+1];
    }

    if(a == m && idxs_by.size() == 0){
        cout << strs[0].first << ln;
        return 0;
    }
    for (auto& [naipe, idxs] : idxs_by) {
        ll ta = a, tb = b;
        forn(i, 0, idxs.size()) {
            ll prox = nxt[idxs[i]];
            if (prox < idxs[i]) prox = tot;
            if (i < ((ll)idxs.size())-1) prox = min(prox, idxs[i+1]);

            // if (strs[idxs[i]].first == strs[idxs[i]].second) continue;
            
            if (naipe == strs[idxs[i]].first && winner[idxs[i]] == 2) {
                ll delta = prox - idxs[i]; 
                ta += delta;
                tb -= delta;
            } 

            else if (naipe == strs[idxs[i]].second && winner[idxs[i]] == 1) {
                ll delta = prox - idxs[i];
                tb += delta;
                ta -= delta;
            }
        }

        debug(ta);
        debug(tb);
        if (ta == m) {
            cout << naipe << ln;
            return 0;
        }
    }

    cout << "*" << ln;

    
    return 0;
}
