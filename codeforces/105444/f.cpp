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

struct ld {
    long double val;
    static constexpr long double eps = 0.000000000001;

    ld(ll x) : val(x) {};
    ld(double x) : val(x) {};
    ld(long double x) : val(x) {};

    bool operator < (const ld o) const { return (val < o.val - eps); }
    bool operator <= (const ld o) const { return (val < o.val + eps); }
    bool operator > (const ld o) const { return (val > o.val + eps); }
    bool operator == (const ld o) const { return (val > o.val - eps) && (val < o.val + eps); }
    bool operator != (const ld o) const { return (val < o.val - eps) || (val > o.val + eps); }
    ld operator + (const ld o) const { return val + o.val; }
    ld operator - (const ld o) const { return val - o.val; }
    ld operator * (const ld o) const { return val * o.val; }
    ld operator / (const ld o) const { return val / o.val; }

};

int main(){
    _;
    ll n, m, k; cin >> n >> m >> k;
    vector<p64> a(n);
    forn(i, 0, n) cin >> a[i].first, a[i].second = i+1;
    sort(a.begin(), a.end());

    if (k % m != 0) {
        cout << "impossible" << ln;
        return 0;
    }
    k /= m;

    set<p64> down, up;
    forn(i, 0, n-k) down.insert(a[i]);
    forn(i, n-k, n) up.insert(a[i]);

    ld avg(0ll);
    ll positive = 0;
    ll count = 0;

    v64 ans(n);
    ll curr = 0;

    while (down.size() || up.size()) {
        bool changed = false;
        while (down.size() && avg*m > prev(down.end())->first) {
            count++;
            ans[curr++] = prev(down.end())->second;
            debug(prev(down.end())->first);
            down.erase(prev(down.end()));
            avg = ld(positive) / ld(count);
            changed = true;
        }

        while (up.size() && avg*m <= up.begin()->first) {
            positive++;
            count++;
            ans[curr++] = up.begin()->second;
            debug(up.begin()->first);
            debug(avg.val*m);
            up.erase(up.begin());
            avg = ld(positive) / ld(count);
            debug(avg.val*m);
            changed = true;
        }
        if (!changed && (down.size() || up.size())) {
            cout << "impossible" << ln;
            return 0;
        }
    }

    forn(i, 0, n) cout << ans[i] << " \n"[i==n-1]; 



    return 0;
}