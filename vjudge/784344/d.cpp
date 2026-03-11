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

struct node {
	pair<ll, ll> val;
	ll lazy;
	node *l, *r;
	node() {}
	node(pair<ll, ll> v) : val(v), lazy(0), l(NULL), r(NULL) {}

	void prop() {
		val.first += lazy;
		if (l) l->lazy += lazy;
		if (r) r->lazy += lazy;
		lazy = 0;
	}
};

void merge(node*& a, node* b) {
	if (!a) swap(a, b);
	if (!b) return;
	a->prop(), b->prop();
	if (a->val > b->val) swap(a, b);
	merge(rand()%2 ? a->l : a->r, b);
}

pair<ll, ll> pop(node*& R) {
	R->prop();
	auto ret = R->val;
	node* tmp = R;
	merge(R->l, R->r);
	R = R->l;
	if (R) R->lazy -= ret.first;
	delete tmp;
	return ret;
}

void apaga(node* R) { if (R) apaga(R->l), apaga(R->r), delete R; }

ll dmst(ll n, ll r, vector<pair<p64, ll>>& ar) {
	vector<ll> p(n); iota(p.begin(), p.end(), 0);
	function<ll(ll)> find = [&](ll k) { return p[k]==k?k:p[k]=find(p[k]); };
	vector<node*> h(n);
	for (auto e : ar) merge(h[e.first.second], new node({e.second, e.first.first}));
	vector<ll> pai(n, -1), path(n);
	pai[r] = r;
	ll ans = 0;

	for (ll i = 0; i < n; i++) { // vai conectando todo mundo
		ll u = i, at = 0;
		while (pai[u] == -1) {
			if (!h[u]) { // nao tem
				for (auto j : h) apaga(j);
				return INF;
			}
			path[at++] = u, pai[u] = i;
			auto [mi, v] = pop(h[u]);
			ans += mi;

			if (pai[u = find(v)] == i) { // ciclo
				while (find(v = path[--at]) != u)
					merge(h[u], h[v]), h[v] = NULL, p[find(v)] = u;
				pai[u] = -1;
			}
		}
	}
	for (auto i : h) apaga(i);
	return ans;
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<pair<p64,ll>> g;
    forn(i, 0, m){
        ll a, b, w; cin >> a >> b >> w;
        g.push_back({{a,b}, w});
    }

    ll cost = dmst(n, 0, g);

    if(cost == INF) cout << "Possums!" << ln;
    else cout << cost << ln;
}

int main(){
    _; ll t; cin >> t;
    forn(i, 0, t){
        cout << "Case #" << i+1 << ": "; 
        solve();
    }
    return 0;
}