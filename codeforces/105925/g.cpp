/******************************************************************************
 *  template.cpp – ICPC-LIB (versão resumida aqui, sem dependências externas) *
 ******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

#define forn(i,s,e) for (int i = (s); i < (e); ++i)
#define all(x)  (x).begin(), (x).end()
#define pb      push_back
#define eb      emplace_back
#define sz(x)   (int)(x).size()
#define fi      first
#define se      second
#define endl    '\n'

#ifdef DEBUG
#   define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#else
#   define dbg(x) (void)0
#endif

/******************************************************************************
 *  Dinic – fluxo máximo (unitário, suficiente aqui)                          *
 ******************************************************************************/
struct Edge {
    int to, rev, cap;
};
struct Dinic {
    vector<vector<Edge>> g;
    vector<int> level, it;
    int n, s, t;
    Dinic(int N=0){ init(N); }
    void init(int N){
        n=N; g.assign(n,{}); level.resize(n); it.resize(n);
    }
    void add_edge(int u,int v,int c){
        Edge a{v,(int)g[v].size(),c};
        Edge b{u,(int)g[u].size(),0};
        g[u].pb(a); g[v].pb(b);
    }
    bool bfs(){
        fill(all(level),-1);
        queue<int> q; q.push(s); level[s]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(const auto& e:g[u])
                if(e.cap && level[e.to]==-1){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
        }
        return level[t]!=-1;
    }
    int dfs(int u,int f){
        if(!f || u==t) return f;
        for(int &i=it[u]; i<sz(g[u]); ++i){
            Edge &e=g[u][i];
            if(e.cap && level[e.to]==level[u]+1){
                int ret=dfs(e.to,min(f,e.cap));
                if(ret){
                    e.cap-=ret;
                    g[e.to][e.rev].cap+=ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    int maxflow(int S,int T){
        s=S; t=T;
        int flow=0;
        while(bfs()){
            fill(all(it),0);
            while(int pushed=dfs(s,INT_MAX)) flow+=pushed;
        }
        return flow;
    }
};
/******************************************************************************
 *  Solução                                                                    *
 ******************************************************************************/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin>>N)) return 0;
    int quota[6]; forn(v,1,6) cin>>quota[v];

    /* valores permitidos por vértice (bitmask) */
    vector<int> mask(N+1);
    forn(i,1,N+1){
        int m; cin>>m;
        int mk=0;
        forn(j,0,m){ int x; cin>>x; mk |= 1<<(x-1); }
        mask[i]=mk;
    }

    /* árvore */
    vector<vector<int>> g(N+1);
    forn(i,0,N-1){
        int u,v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }

    /* parent/depth para reconstruir caminho */
    vector<int> parent(N+1), depth(N+1);
    {
        vector<int> st{1}; parent[1]=0; depth[1]=0;
        while(!st.empty()){
            int u=st.back(); st.pop_back();
            for(int v:g[u]) if(v!=parent[u]){
                parent[v]=u;
                depth[v]=depth[u]+1;
                st.pb(v);
            }
        }
    }

    auto path=[&](int u,int v){
        vi a,b;
        while(u!=v){
            if(depth[u]>=depth[v]){
                a.pb(u);
                u=parent[u];
            }else{
                b.pb(v);
                v=parent[v];
            }
        }
        a.pb(u);
        reverse(all(b));
        a.insert(a.end(),all(b));
        return a;          /* ordem de u para v */
    };

    /* caminhos especiais -> arestas direcionadas (u -> v exige val[u] < val[v]) */
    int P; cin>>P;
    vector<vector<int>> dag(N+1);
    vector<int> indeg(N+1);
    forn(k,0,P){
        int x,y; cin>>x>>y;
        vi p = path(x,y);
        forn(i,0,sz(p)-1){
            int u=p[i]  , v=p[i+1];
            dag[u].pb(v);
            ++indeg[v];
        }
    }

    /* ordenação topológica e maior caminho */
    queue<int> q;
    vector<int> topo;
    forn(i,1,N+1) if(!indeg[i]) q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        topo.pb(u);
        for(int v:dag[u]) if(--indeg[v]==0) q.push(v);
    }
    if(sz(topo)!=N){               /* ciclo -> impossível */
        cout<<-1<<endl;
        return 0;
    }

    vector<int> dist(N+1,0);
    for(int u:topo)
        for(int v:dag[u])
            dist[v]=max(dist[v],dist[u]+1);

    vector<int> lo(N+1);           /* valor mínimo permitido pelo DAG */
    forn(i,1,N+1){
        lo[i]=dist[i]+1;
        if(lo[i]>5){ cout<<-1<<endl; return 0; }
    }

    /* construção do fluxo bipartido */
    const int SRC = 0;
    const int VAL_BASE = 1;        /* 1..5 */
    const int NODE_BASE = 6;       /* 1..N -> 6..(5+N) */
    const int SNK = 6+N;
    Dinic din(SNK+1);

    forn(v,1,6) din.add_edge(SRC, VAL_BASE+v-1, quota[v]);

    forn(i,1,N+1){
        int id = NODE_BASE+i-1;
        din.add_edge(id,SNK,1);
        forn(v,1,6)
            if( (mask[i]&(1<<(v-1))) && v>=lo[i] )
                din.add_edge(VAL_BASE+v-1,id,1);
    }

    if(din.maxflow(SRC,SNK)!=N){
        cout<<-1<<endl;
        return 0;
    }

    /* reconstruir atribuição */
    vector<int> ans(N+1,0);
    forn(v,1,6){
        int vid = VAL_BASE+v-1;
        for(const auto& e:din.g[vid])
            if(e.to>=NODE_BASE && e.to<NODE_BASE+N && e.cap==0){
                int node = e.to - NODE_BASE + 1;
                ans[node]=v;
            }
    }

    forn(i,1,N+1){
        cout<<ans[i]<<(i==N?'\n':' ');
    }
    return 0;
}
