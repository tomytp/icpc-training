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

struct flag{
    char cor1, cor2, cor3;
    ll siz;

    bool operator == (const flag f) const {
        return (cor1 == f.cor1) && (cor2 == f.cor2) && (cor3 == f.cor3) && (siz == f.siz);
    }
};

int main(){
    _; ll n, m; cin >> n >> m;
    vector<string> blanket(n);
    forn(i,0,n) cin >> blanket[i];

    vector<v64> nxt_vert(n, v64(m));
    forn(j, 0, m){
        ll ini = 0, fim = 0;
        while (ini < n) {
            char c = blanket[ini][j];
            while(fim < n && blanket[fim][j] == c) fim++;
            while(ini < fim){
                nxt_vert[ini][j] = fim;
                ini++;
            }
        }
        
    }
    forn(i, 0, n) debugv(nxt_vert[i]);

    vector<vector<flag>> band(n, vector<flag>(m));
    forn(i, 0, n)
    forn(j, 0, m){
        ll nx = nxt_vert[i][j];
        ll siz = nx - i;
        band[i][j].cor1 = blanket[i][j];

        if(nx == n){
            band[i][j].siz = -1;
            continue;
        }
        band[i][j].cor2 = blanket[nx][j];

        ll nx2 = nxt_vert[nx][j];
        if(nx2 - nx != siz || nx2 == n){
            band[i][j].siz = -1;
            continue;
        }
        band[i][j].cor3 = blanket[nx2][j];

        ll nx3 = nxt_vert[nx2][j];
        if(nx3 - nx2 < siz){
            band[i][j].siz = -1;
            continue;
        }

        band[i][j].siz = siz;
    }

    ll resp = 0;
    forn(i, 0, n){
        ll l = 0, r = 0;
        while(l < m && r < m){
            if (band[i][r].siz == -1) {
                while (l < r) resp += r - l++;
                l++;
                r++;
                continue;
            }
            if (!(band[i][r] == band[i][l])) {
                while (l < r) resp += r - l++;
                continue;
            }
            r++;
        }
        debug(l);
        debug(r);
        while (l < r) resp += r - l++;
    }

    cout << resp << ln;

    return 0;
}