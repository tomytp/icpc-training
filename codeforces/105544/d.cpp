#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln '\n';

#if defined(DEBUG)
    #define _ (void) 0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln;
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void) 0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<p64> lado = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
vector<p64> diag = {{1,1}, {1,-1}, {-1, 1}, {-1, -1}};

ll cnt = 1;
void solve(){
    ll n, m, d1, d2;
    cin >> n >> m >> d1 >> d2;
    vector<string> vec(n);
    forn(i,0,n) cin >> vec[i];
    vector<v64> resp(n, v64(m, 0));

    forn(i,0,n){
        forn(j,0,m){
            if(vec[i][j] == 'V'){
                resp[i][j] = -1;
                continue;
            }
            for(auto [l, r] : lado){
                if(i+l < 0 || i + l >= n) continue;
                if(j+r < 0 || j + r >= m) continue;
                if(vec[i+l][j+r] != 'V') continue;
                resp[i][j] = max(resp[i][j], d1);
            }
            for(auto [l, r] : diag){
                if(i+l < 0 || i + l >= n) continue;
                if(j+r < 0 || j + r >= m) continue;
                if(vec[i+l][j+r] != 'V') continue;
                resp[i][j] = max(resp[i][j], d2);
            }
        }
    }

    cout << "Airplane #" << cnt << ":" << ln;
    cnt++;
    forn(i,0,n){
        forn(j,0,m){
            if(resp[i][j] != -1) cout << resp[i][j];
            else cout << "V";
        }
        cout << ln;
    }
}

int main() {
    _;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}