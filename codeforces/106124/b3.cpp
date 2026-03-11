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
const ll MAXH = 350;
const ll MAXW = 900;
const ll MAXMAX = 905;

bool knapsack(vector<pair<p64, ll>>& books, ll idx, ll c1, ll c2, set<ll>& ans){
    v64 sums(MAXMAX, -1);
    ll tot = 0;
    forn(i,0,idx){
        tot += books[i].first.second;
        for(ll j = MAXMAX-1; j >= 0; j--){
            if(j+ books[i].first.second >= MAXMAX) continue;
            if(sums[j] == -1) continue;
            if(sums[j+ books[i].first.second] != -1) continue;
            sums[j+ books[i].first.second] = i;
        }

        if(sums[books[i].first.second] != -1) continue;
        sums[books[i].first.second] = i;
    }

    forn(i, max(tot-c2, 1ll), c1+1){
        if(sums[i] != -1){
            ll x = i;
            while(x > 0){
                ans.insert(sums[x]);
                x -= books[sums[x]].first.second;
            }
            return true;
        }

    }
    return false;
}

int main(){
    ll n, h, w; cin >> n >> h >> w;

    vector<pair<p64, ll>> books(n);
    forn(i,0,n){
        cin >> books[i].first.first >> books[i].first.second;
        books[i].second = i;
    }

    sort(books.begin(), books.end());

    ll grossura = 0;
    ll deitura = 0;
    ll deit_size = -1;
    set<ll> ans;
    bool tenta = false;
    bool bom = false;

    for(ll i = n-1; i >=0; i--){
        if(books[i].first.first > h){
            deit_size = max(deit_size, books[i].first.first);
            deitura += books[i].first.second;
            tenta = true;
            continue;
        }
        if(tenta){
            tenta = false;
            ll c1 = w - deit_size - grossura;
            ll c2 = h - deitura;
            if(c1 < 0) continue;
            if(c2 < 0) continue;
            if(knapsack(books, i+1, c1, c2, ans)){
        
                bom = true;
                break;
            }
        }
        ll c1 = w - max(deit_size, books[i].first.first) - grossura;
        ll c2 = h - (books[i].first.second + deitura);
        if(c1 < 0) continue;
        if(c2 < 0) continue;
        if(knapsack(books, i, c1, c2, ans)){
            bom = true;
            break;
        }
        grossura += books[i].first.second;
        ans.insert(i);
    }

    if(!bom){
        cout << "impossible" << ln;
        return 0;
    }
    cout << "upright ";
    for(ll x: ans) cout << books[x].second+1 << " ";; cout << ln;
    cout << "stacked ";
    set<p64> aux;
    forn(i,0,n) if(ans.count(i) == 0){
        aux.insert({books[i].first.first, books[i].second});
    }

    for(auto it = aux.rbegin(); it != aux.rend(); it++){
        cout << it->second + 1<< " ";
    }    
    cout << ln;

}