#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct dsu {
	vector<ll> id, sz;
	stack<stack<pair<ll&, ll>>> st;
    ll comps;

	dsu(ll n) : id(n), sz(n, 1), comps(n) { 
		iota(id.begin(), id.end(), 0), st.emplace(); 
	}
		
	void checkpoint() { st.emplace(); }
	
	void rollback() {
		while(st.top().size()) {
			auto [end, val] = st.top().top(); st.top().pop();
			end = val;
		}
		st.pop();
	}

	ll find(ll a) { return a == id[a] ? a : find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		save(sz[a]), save(id[b]);
		sz[a] += sz[b], id[b] = a;
        save(comps);
        comps--;
	}

    void save(ll &x) { st.top().emplace(x, x); }
};

struct query {
    ll a, b, t;
};

struct node {
    ll lm, rm;
    unique_ptr<node> lc, rc;
    vector<query> queries;

    node(ll lm_, ll rm_) : lm(lm_), rm(rm_) {
        if (lm != rm) {
            ll mid = (lm + rm) / 2;
            lc = make_unique<node>(lm, mid);
            rc = make_unique<node>(mid + 1, rm);
        }
    }

    void add_query(query& q, ll lq, ll rq)  {
        if (lq <= lm && rq >= rm) {
            queries.push_back(q);
        } else if (lq > rm || rq < lm) {
            return;
        } else {
            lc->add_query(q, lq, rq);
            rc->add_query(q, lq, rq);
        }
    }

    void dfs(dsu& sdu) {
        sdu.checkpoint();
        for(auto& q : queries) {
            if (q.t == 0) sdu.uni(q.a, q.b);
        }

        for (auto& q : queries) if (q.t == 1) {
            cout << sdu.comps << ln;
        }

        if (lm != rm) {
            lc->dfs(sdu);
            rc->dfs(sdu);    
        }
        
        sdu.rollback();
    }
};

int main(){
    _;
    // freopen("connect.in", "r", stdin);
    // freopen("connect.out", "w", stdout);

    ll n, k; cin >> n >> k;
    if (k == 0) return 0;
    
    map<p64, ll> mp;
    node seg(0, k-1);

    forn(i, 0, k) {
        char c; cin >> c;
        if (c == '?') {
            query q = {-1, -1, 1};
            seg.add_query(q, i, i);
        } else {
            ll a, b; cin >> a >> b;
            a--; b--;
            ll x = min(a, b);
            ll y = max(a, b);

            if (c == '+') mp[{x, y}] = i;
            else {
                query q = {x, y, 0};
                seg.add_query(q, mp[{x,y}], i-1);
                mp.erase({x, y});
            }
        }
    }

    for (auto& [key, val] : mp) {
        query q = {key.first, key.second, 0};
        seg.add_query(q, val, k-1);
    }

    dsu sdu(n);
    seg.dfs(sdu);

    return 0;
}