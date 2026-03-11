#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 401;

ll n;
ll d[MAX][MAX], d1[MAX][MAX];

struct query {
    ll a, b, idx;
};

vector<vector<query>> quente, fria;
v64 ans;


void print() {
    forn(i, 0, n) {
        forn(j, 0, n) {
            cout << d[i][j] << "\t\n"[j == n-1];
        }
    }
}

void floyd_warshall(map<ll, v64>& order, vector<vector<query>>& qr, ll mat[MAX][MAX]) {
    ll ord_temp = 0;

    for (auto& [temp, vec] : order) {
        for(auto idx : vec) {            
            forn(i, 0, n) {
                forn(j, 0, n) mat[i][j] = min(mat[i][j], mat[i][idx] + mat[idx][j]);
            }
            
        }

        for (auto q : qr[ord_temp]) {
            ans[q.idx] = mat[q.a][q.b];
        }

        ord_temp++;
    }
}



int main() {
    _;
    ll r; cin >> n >> r;
    v64 temp(n);

    forn(i, 0, n) {
        forn(j, 0, n) d[i][j] = INF, d1[i][j] = INF;
    }

    forn(i, 0, n) cin >> temp[i];
    forn(i, 0, r) {
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        d1[a][b] = c;
        d1[b][a] = c;
    }

    map<ll, v64> t1, t2;
    forn(i, 0, n) {
        t1[temp[i]].push_back(i);
        t2[-temp[i]].push_back(i);
    }

    ll q; cin >> q;
    ans.resize(q);
    quente.resize(n);
    fria.resize(n);
    forn(i, 0, q) {
        ll a, b, k, t; cin >> a >> b >> k >> t;
        a--; b--; k--;
        k = min(k, (ll)t1.size() - 1);
        if (t == 0) {
            fria[k].push_back({a, b, i});
        } else {
            quente[k].push_back({a, b, i});
        }
    }


    floyd_warshall(t1, fria, d);
    floyd_warshall(t2, quente, d1);
    
    forn(i, 0, q) cout << (ans[i] != INF ? ans[i] : -1) << ln;
        
    return 0;
}