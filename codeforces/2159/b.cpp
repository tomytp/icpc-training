#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
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

struct dsu {
	vector<ll> id, sz;

	dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void uni(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

struct ed {
    ll a, b, c;
    bool operator<(ed const& o) const { 
        if (c != o.c) return c < o.c;
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        return false;
    }
};

int main(){
    _;
    ll t; cin >> t;
    forn(kk, 0, t) {
        ll n; cin >> n;
        v64 v(n);
        forn(i, 0, n) cin >> v[i];
        
        vector<ed> tot;
        forn(i, 0, n) tot.push_back({n, i, v[i]});
        
        forn(i, 1, n) {
            tot.push_back({i, i-1, abs(v[i]-v[i-1])});
        }
        sort(tot.begin(), tot.end());

        dsu sdu(n+1);
        for(auto x : tot) {
            sdu.uni(x.a, x.b);
            if (sdu.sz[sdu.find(0)] == n+1) {
                cout << "Case #" << kk+1 << ": " << x.c << ln;
                break;
            }
        }        

    }
    return 0;
}