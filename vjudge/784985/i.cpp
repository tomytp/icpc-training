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

typedef v64 vi;
typedef p64 pii;


struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct Edge { ll a, b; ll w; };
struct Node { /// lazy skew heap node
	Edge key;
	Node *l, *r;
	ll delta;
	void prop() {
		key.w += delta;
		if (l) l->delta += delta;
		if (r) r->delta += delta;
		delta = 0;
	}
	Edge top() { prop(); return key; }
};
Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ?: b;
	a->prop(), b->prop();
	if (a->key.w > b->key.w) swap(a, b);
	swap(a->l, (a->r = merge(b, a->r)));
	return a;
}
void pop(Node*& a) { a->prop(); a = merge(a->l, a->r); }

pair<ll, vi> dmst(int n, int r, vector<Edge>& g) {
	RollbackUF uf(n);
	vector<Node*> heap(n);
	for (Edge e : g) heap[e.b] = merge(heap[e.b], new Node{e});
	ll res = 0;
	vi seen(n, -1), path(n), par(n);
	seen[r] = r;
	vector<Edge> Q(n), in(n, {-1,-1}), comp;
	deque<tuple<int, int, vector<Edge>>> cycs;
	forn(s,0,n) {
		int u = s, qi = 0, w;
		while (seen[u] < 0) {
			if (!heap[u]) return {-1,{}}; 
			Edge e = heap[u]->top();
			heap[u]->delta -= e.w, pop(heap[u]);
			Q[qi] = e, path[qi++] = u, seen[u] = s;
			res += e.w, u = uf.find(e.a);
			if (seen[u] == s) { /// found cycle, contract
				Node* cyc = 0;
				int end = qi, time = uf.time();
				do cyc = merge(cyc, heap[w = path[--qi]]);
				while (uf.join(u, w));
				u = uf.find(u), heap[u] = cyc, seen[u] = -1;
				cycs.push_front({u, time, {&Q[qi], &Q[end]}});
			}
		}
		forn(i,0,qi) in[uf.find(Q[i].b)] = Q[i];
	}

	for (auto& [u,t,compp] : cycs) { // restore sol (optional)
		uf.rollback(t);
		Edge inEdge = in[u];
		for (auto& e : compp) in[uf.find(e.b)] = e;
		in[uf.find(inEdge.b)] = inEdge;
	}
	forn(i,0,n) par[i] = in[i].a;
	return {res, par};
}

int main(){
    _;
    // freopen ("input.txt","r",stdin);
    // freopen ("output.txt","w",stdout);

    ll n, m; cin >> n >> m;
    vector<Edge> edges(m);
    map<p64, ll> trad;

    forn(i,0,m){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges[i] = {a, b, c};
        trad[{a, b}] = i;
    }

    auto ans = dmst(n, 0, edges);

    if(ans.first == -1){
        cout << -1 << ln;
        return 0;
    }

    cout << ans.first << ln; 
    forn(i, 0, sz(ans.second)) {
        if (ans.second[i] >= 0 && edges[trad[{ans.second[i], i}]].w){
            cout << trad[{ans.second[i], i}] +1 << " ";
        }
    }
    cout << ln;
    return 0;
}