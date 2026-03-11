#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = s; i < (e); i++)
#define sz(u) ((ll) u.size())
#define ln "\n"

#ifdef DEBUG
#define trace(u) u
#define _
#else
#define trace(u)
#define _ ios::sync_with_stdio(0); cin.tie(0)
#endif

#define debug(u) trace(cout << #u " = " << u << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll testa(ll t, ll h, ll w, vector<v64>& mat, map<ll, p64>& inv){

    p64 post = inv[t];
    vector<v64> dist(h, v64(w, INF));
    vector<v64> vis(h, v64(w, 0));
    dist[post.first][post.second] = 0;
    vis[post.first][post.second] = 1;
    
    forn(i,0,h*w){
        debug(i);
        ll x = -1;
        ll y = -1;
        ll curr = i;
        p64 prox = inv[i];        
        ll proxval = INF;
        stack<p64> st;

        if(dist[prox.first][prox.second] != INF) continue;

        auto arruma = [&](p64 tenta){
            ll val = mat[tenta.first][tenta.second];

            if(abs(val - t) > abs(proxval - t)) return;
            if(abs(val - t) == abs(proxval - t)){
                if(abs(val - curr) > abs(proxval - curr)) return;
            }

            proxval = val;
            prox = tenta;
        };

        do{
            proxval = INF;
            x = prox.first;
            y = prox.second;
            debug(x);
            debug(y);
            st.push({x,y});
            vis[x][y] = 1; 

            if(x > 0){
                p64 tenta = {x-1, y};
                arruma(tenta);
            }
            if(y > 0){
                p64 tenta = {x, y-1};
                arruma(tenta);
            }
            if(x < h-1){
                p64 tenta = {x+1, y};
                arruma(tenta);
            }
            if(y < w-1){
                p64 tenta = {x, y+1};
                arruma(tenta);
            }
        } while (!vis[x][y]);

        if(dist[x][y] == INF) return INF;

        ll d = dist[x][y];
        ll cnt = 1;

        while (!st.empty()){
            auto [xx, yy] = st.top();
            st.pop();
            dist[xx][yy] = d + cnt;
            cnt++;
        }
    }   

    ll resp = 0;
    forn(i,0,h){
        forn(j,0,w){
            resp += dist[i][j];
        }
    }
    return resp;
}


int main() {
    _;
    ll h, w; cin >> h >> w;
    vector<v64> mat(h, v64(w));
    map<ll, p64> inv;

    forn(i,0,h){
        forn(j,0,w){
            cin >> mat[i][j];
            mat[i][j]--;
            inv[mat[i][j]] = {i,j};
        }
    }

    ll bestval = INF;
    ll bestidx = -1;

    forn(i,0,h*w){
        ll val = testa(i,h, w, mat, inv);
        if(val < bestval){
            bestval = val;
            bestidx = i;
        }
    }

    if(bestval == INF){
        cout << "impossible" << ln;
        return 0;
    }
    
    cout << inv[bestidx].first+1 << " " << inv[bestidx].second+1 << ln;
    return 0;
}