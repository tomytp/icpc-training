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

struct dsu {
    v64 id, size;
    dsu(ll n) : id(n), size(n,1) { iota(id.begin(), id.end(), 0);}

    ll find(ll a) {return a == id[a] ? a : id[a] = find(id[a]);};

    void uni(ll a, ll b){
        a = find(a), b = find(b);
        if(a == b) return; 
        if(size[a] < size[b]) swap(a,b);
        size[a] += size[b], id[b] = a;
    }
};

vector<string> gen(ll n){
    vector<string> m(n, string(2*n-1, '.'));
    forn(i, 0, n){
        forn(j, 0, 2*n-1){
            if(j <= n-2-i) m[i][j] = '#';
            else if(j >= n+i) m[i][j] = '#';
            else m[i][j] = (".C"[uniform(0,1)]);
        }
    }

    return m;
}

//nao testa se impossible esta certo!!!!!!!!!!!
bool test(vector<string> m, ll n) {
    dsu sdu(n*(2*n-1));

    forn(i, 0, n){
        forn(j, 0, 2*n-1){
            if(i > 0) if(m[i][j] == m[i-1][j]) sdu.uni(i*(2*n-1) + j, (i-1)*(2*n-1) + j);
            if(j > 0) if(m[i][j] == m[i][j-1]) sdu.uni(i*(2*n-1) + j, i*(2*n-1) + (j-1));
        }
    }

    set<ll> heads;
    forn(i,0, n*(2*n-1)) heads.insert(sdu.find(i));

    if(sz(heads) == 4) return true;
    else return false;
}

void printi(vector<string>& m) {
    ll n = sz(m);
    forn(i, 0, n) {
        forn(j, 0, m[i].size()) {
            if (m[i][j] != 'A' && m[i][j] != '#') m[i][j] = 'B';
        }
    }
} 

void solve_ruim(vector<string>& m, ll tot){
    ll n = sz(m);
    ll used = 0;
    if(m[n-1][0] != 'C' || m[n-1][1] != 'C'){
        for(ll i = 2*n-2; i>= 0; i--){
            if (m[n-1][i] == 'C') used++;
            m[n-1][i] = 'A';
            if (used == tot) break; 
        }
        printi(m);
        return;
    }

    if (m[n-1][2*n-3] != 'C' || m[n-1][2*n-2] != 'C') {
        forn(i, 0, 2*n-2) {
            if (m[n-1][i] == 'C') used++;
            m[n-1][i] = 'A';
            if (used == tot) break;
        }
        printi(m);
        return;
    }

    ll rtrig = 0;
    forn(i,0, n-1) {
        forn(j, n, 2*n-1) {
            if (m[i][j] == 'C') rtrig++;
            if(rtrig) break;
            
        }
        if (rtrig) break;
    }

    if (rtrig) {
        for(ll i = 2*n-2; i>= 0; i--){
            if (m[n-1][i] == 'C') used++;
            m[n-1][i] = 'A';
            if (used == tot-1) break; 
        }

        
        for(ll i = 2*n-2; i >= n; i--) {
            for(ll j = n-1; j >= 0; j--) {
                if (m[j][i] == '#') continue;
                if (m[j][i] == 'C') used++;
                m[j][i] = 'A';
                if (used == tot) break;
            }
            if (used == tot) break;
        }
        printi(m);
        return;
    }
    
    forn(i, 0, 2*n-2) {
        if (m[n-1][i] == 'C') used++;
        m[n-1][i] = 'A';
        if (used == tot-1) break;
    }
    
    forn(i, 0, 2*n-1) {
        for(ll j = n-1; j >= 0; j--) {
            if (m[i][j] == '#') continue;
            if (m[j][i] == 'C') used++;
            m[j][i] = 'A';
            if (used == tot) break;
        }
        if (used == tot) break;
    }
    printi(m);  
}

bool solve(vector<string>& m, ll n) {
    // forn(i, 0, n) cin >> m[i];
    ll tot = 0;
    forn(i, 0, n) {
        for (auto c : m[i]) {
            if (c == 'C') tot++;
        }
    }
    if (tot & 1) {
        return false;
    }
    tot /= 2;

        if (n == 2 && tot == 2) {
        cout << "impossible" << ln;
        return false;
    } 

    if(tot == 3) {
        if (m[n-1][0] == 'C' && m[n-1][1] == 'C' && m[n-1][2*n-2] == 'C' && m[n-1][2*n-3] == 'C' && m[0][n-1] == 'C' && m[1][n-1]) {
            cout << "impossible" << ln;
            return false;
        }
    }

    ll under = 0;
    for(auto c : m[n-1]) under += (c == 'C');

    if(under == tot + 1){
        solve_ruim(m, tot);
        return true;
    }

    ll used = 0;
        if (under == tot) {
        forn(i, 0, 2*n-1) m[n-1][i] = 'A';
        printi(m);
        return true;
    }
    if (under > tot) {
        forn(i, 0, 2*n-1) {
            if (m[n-1][i] == 'C') used++;
            m[n-1][i] = 'A';
            if (used == tot) break;
        }
        printi(m);
        return true;
    }


    for(ll i = n-1, st = 0, nd = 2*n-2; i >= 0; i--, st++, nd--) {
        // st -> nd inclusive
        if (m[i][nd] == 'C') used++;
        m[i][nd] = 'A';
        if (used == tot) break; 
        forn(j, st, nd) {
            if (m[i][j] == 'C') used++;
            m[i][j] = 'A';
            if (used == tot) break;
        }
        if (used == tot) break;
    }

    printi(m);

    return true;
}

int main(){
    ll n = 2, counter = 0;
    while(true){
        cout << counter << ln;
        counter++;
        vector<string> m_orig = gen(n);
        vector<string> m = m_orig;
        // forn(i, 0, n){
        //     cout << m[i] << ln;
        // }
        // debug('o');
        bool s = solve(m, n);
        // debug('o');
        if(s && !test(m, n)){
            forn(i, 0, n){
                cout << m_orig[i] << ln;
            }

            cout << ln;

            forn(i, 0, n){
                cout << m[i] << ln;
            }
            break;
        }
    }
}