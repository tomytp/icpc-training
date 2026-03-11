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
const ll TAM = 1000;
pair<ll, char> mov;
void print(string s){
    cout << s << " " << mov.first << " " << mov.second;
}

void solve() {
    ll n; cin >> n;
    ll blue_count = 0, red_count = 0;

    vector<pair<ll, char>> fita(TAM);

    forn(i, 0, n) {
        ll x, m;
        char c;
        cin >> x >> m >> c;
        if (c == 'R') fita[x] = {m, 'R'}, red_count += m;
        else fita[x] = {m, 'B'}, blue_count += m;
    }
    
    forn(i,0,1000){
        if(fita[i].second == 'R') mov = {i, '+'};
    }

    if(blue_count == red_count) {print("Draw"); return;}

    if(red_count > blue_count)
        while (true){
            ll idxv = -1, idxa = -1;
            for (ll i = TAM-1; i >= 0; i--){
                if(idxa == -1){
                    if(fita[i].second == 'B') idxa = i;
                }else{
                    if(fita[i].second == 'R') idxv = i;
                }
            }
            if(idxv == -1) {print("First"); return;}

            fita[idxa].first--;
            if(fita[idxa].first == 0) fita[idxa].second = 'O';
            if(idxa + 1 == TAM) {print("Draw"); return;}

            if(fita[idxa+1].second == 'B') fita[idxa+1].first++;
            if(fita[idxa+1].second == 'R') fita[idxa+1].first--;
            if(fita[idxa+1].second == 'O') fita[idxa+1].first++, fita[idxa+1].second == 'B';
            if(fita[idxa+1].first == 0) fita[idxa].second = 'O';
            
            fita[idxa].first--;
            if(fita[idxa].first == 0) fita[idxa].second = 'O';
            if(idxa + 1 == TAM) {print("Draw"); return;}

            if(fita[idxa+1].second == 'B') fita[idxa+1].first++;
            if(fita[idxa+1].second == 'R') fita[idxa+1].first--;
            if(fita[idxa+1].second == 'O') fita[idxa+1].first++, fita[idxa+1].second == 'B';
            if(fita[idxa+1].first == 0) fita[idxa].second = 'O';
        }
    }
    
    
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}