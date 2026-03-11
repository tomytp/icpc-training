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

ll adjust (ll a, ll low) {
    if (a < low) a = low;
    return a;
}

int main(){
    _;
    ll n, m; cin >> n >> m;
    v64 v(n); forn(i, 0, n) cin >> v[i];
    v64 vc = v;
    priority_queue<p64> pq;
    forn(i, 0, n) {
        pq.push({v[i], i});
    }
    while (pq.size()) {
        auto [val, i] = pq.top(); pq.pop();
        if (val != v[i]) continue;
        if (i >= 1 && v[i-1] < adjust(v[i-1], v[i] - m)) v[i-1] = adjust(v[i-1], v[i] - m), pq.emplace(v[i-1], i-1);
        if (i < n-1 && v[i+1] < adjust(v[i+1], v[i] - m)) v[i+1] = adjust(v[i+1], v[i] - m), pq.emplace(v[i+1], i+1);
    }
    forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    return 0;
}