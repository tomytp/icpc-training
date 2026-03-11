#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXN = 508;
const ll MAXAGE = 108;

vector<v64> dag(MAXN), freq(MAXN, v64(MAXAGE));
v64 age(MAXN), pos(MAXN);

void dfs_build(ll age_, ll curr, vector<bool>& vis){
    vis[curr] = true;

    for(auto u : dag[curr]){
        if(vis[u]) continue;
        freq[u][age_]++;
        dfs_build(age_, u, vis);
    }
} 

void dfs_query(ll new_age, ll old_age, ll curr, vector<bool>& vis){
    vis[curr] = true;

    for(auto u : dag[curr]){
        if(vis[u]) continue;
        freq[u][new_age]++;
        freq[u][old_age]--;
        dfs_query(new_age, old_age, u, vis);
    }
}

int main() {
    _; ll n, m, q; cin >> n >> m >> q;
    forn(i, 0, n) cin >> age[i];
    forn(i, 0, m){
        ll a, b; cin >> a >> b;
        a--; b--;
        dag[a].push_back(b);
    }

    forn(i, 0, n){
        vector<bool> vis(n, false);
        dfs_build(age[i], i, vis);
        pos[i] = i;
    }

    forn(i, 0, n){
        debug(i);
        forn(j, 0, MAXAGE){
            debug(j);
            debug(freq[i][j]);
        }
    }

    forn(i, 0, q){
        char c; cin >> c;
        if(c == 'P'){
            ll a; cin >> a; a--;
            bool found = false;
            forn(j, 0, MAXAGE){
                if(freq[pos[a]][j] != 0){
                    cout << j << ln;
                    found = true;
                    break;
                }
            }
            if(!found) cout << "*" << ln;
        }

        if(c == 'T'){
            ll a, b; cin >> a >> b; a--; b--;
            ll pos_a = pos[a], pos_b = pos[b];
            pos[a] = pos_b;
            pos[b] = pos_a;

            vector<bool> vis1(n, false), vis2(n, false);
            dfs_query(age[b], age[a], pos[b], vis1);
            dfs_query(age[a], age[b], pos[a], vis2);


        }
    }

    return 0;
}