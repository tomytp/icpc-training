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
const ll MAXN = 1e6+10;
const ll SQ = 316;

ll ans;
v64 freq(MAXN);
v64 v;

inline void insert(int p) {
    p = v[p];
    ans -= freq[p] * freq[p] * p;
    freq[p]++;
    ans += freq[p] * freq[p] * p;
}

inline void erase(int p) {
    p = v[p];
    ans -= freq[p] * freq[p] * p;
    freq[p]--;
    ans += freq[p] * freq[p] * p;
    
}

#define HILBERT false
vector<int> MO(vector<p64> &q) {
	ans = 0;
	int m = q.size();
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);

	sort(ord.begin(), ord.end(), [&](int l, int r) {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second;
	});
    
	vector<int> ret(m);
	int l = 0, r = -1;

	for (int i : ord) {
		int ql, qr;
		tie(ql, qr) = q[i];
		while (r < qr) insert(++r);
		while (l > ql) insert(--l);
		while (l < ql) erase(l++);
		while (r > qr) erase(r--);
		ret[i] = ans;
	}
	return ret;
}

int main(){
    _;
    ll n, t; cin >> n >> t;
    v.resize(n);
    forn(i, 0, n) cin >> v[i];
    vector<p64> q(t);
    forn(i, 0, t) {
        cin >> q[i].first >> q[i].second;
        q[i].first--; q[i].second--;
    }

    auto ret = MO(q);
    forn(i, 0, t) {
        cout << ret[i] << "\n";
    }
    return 0;
}