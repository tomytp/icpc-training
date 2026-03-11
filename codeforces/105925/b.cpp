/*  template.cpp  —  ponto de partida do tomytp/icpc-lib
    (macros essenciais mantidas; solução completa abaixo)               */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define forn(i,a,b) for (int i = (a); i < (b); ++i)

/* ---------- Aho-Corasick sobre todos os caminhos ---------- */
struct Node {
    int nxt[26];
    int fail;
    int depth;              // |prefixo| que este estado representa
    Node() { memset(nxt, -1, sizeof nxt); fail = 0; depth = 0; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; if (!(cin >> N)) return 0;

    /* ----- árvore de entrada ----- */
    vector<int> par(N, -1);
    forn(i,1,N) { cin >> par[i]; --par[i]; }

    string lab; cin >> lab;                // N-1 letras

    vector<int> head(N, -1), to(N-1), nxtEdge(N-1);
    vector<char> chEdge(N-1);
    forn(i,1,N) {
        int id = i-1, p = par[i];
        to [id] = i;
        chEdge[id] = lab[id]-'a';
        nxtEdge[id] = head[p];
        head[p] = id;
    }

    /* ----- constrói trie dos caminhos ----- */
    vector<Node> ac; ac.reserve(N+1);
    ac.emplace_back();                     // estado 0 = raiz

    vector<int> state(N);                  // estado AC de cada nó
    struct Frame { int u, e, s; };
    vector<Frame> st; st.reserve(N);
    st.push_back({0, head[0], 0});
    state[0] = 0;

    while (!st.empty()) {
        auto &f = st.back();
        if (f.e == -1) { st.pop_back(); continue; }

        int id = f.e; f.e = nxtEdge[id];
        int v  = to[id];
        int c  = chEdge[id];
        int s  = f.s;

        if (ac[s].nxt[c] == -1) {
            ac[s].nxt[c] = (int)ac.size();
            Node n; n.depth = ac[s].depth + 1;
            ac.push_back(n);
        }
        int ns = ac[s].nxt[c];
        state[v] = ns;
        st.push_back({v, head[v], ns});
    }

    /* ----- links de falha (BFS) ----- */
    queue<int> q;
    forn(c,0,26) {
        int v = ac[0].nxt[c];
        if (v != -1) { ac[v].fail = 0; q.push(v); }
        else          ac[0].nxt[c] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        forn(c,0,26) {
            int v = ac[u].nxt[c];
            int f = ac[u].fail;
            if (v != -1) {
                ac[v].fail = ac[f].nxt[c];
                q.push(v);
            } else ac[u].nxt[c] = ac[f].nxt[c];
        }
    }

    /* ----- calcula melhor período ----- */
    int best = 0;
    forn(i,1,N) {                      // ignora raiz
        int s   = state[i];
        int len = ac[s].depth;
        int pi  = ac[ ac[s].fail ].depth;
        int p   = len - pi;
        if (p < len && len % p == 0 && len >= 2*p)
            best = max(best, p);
    }

    cout << best << '\n';
    return 0;
}
