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

    ll calc_box(vector<p64>& v) {
        ll mx = -INF, mmx = INF, my = -INF, mmy = INF;
        for (auto &[a, b] : v) {
            mx = max(a, mx);
            mmx = min(a, mmx);
            my = max(b, my);
            mmy = min(b, mmy);
        }

        ll ans = (abs(mx - mmx) + 1) * ((abs(my - mmy)) + 1);
        if (ans == v.size()) {
            ans += min(abs(mx - mmx) + 1, (abs(my - mmy)) + 1);
        }
        return ans;
    }

    void solve() {
        ll n; cin >> n;
        vector<p64> v(n);
        forn(i, 0, n) cin >> v[i].first >> v[i].second;

        if (n == 1) {
            cout << 1 << ln;
            return ;
        }
        
        ll ans = INF;
        auto v1 = v;
        ll idx = 0, val = -INF;
        forn(i, 0, n) {
            if (v[i].first > val) {
                val = v[i].first;
                idx = i;
            }
        }
        v1.erase(v1.begin() + idx);
        ans = min(ans, calc_box(v1));
        debug(v1.size());
        v1 = v;
        idx = 0, val = -INF;
        forn(i, 0, n) {
            if (v[i].second > val) {
                val = v[i].second;
                idx = i;
            }
        }
        v1.erase(v1.begin() + idx);
        ans = min(ans, calc_box(v1));
        debug(v1.size());

        v1 = v;
        idx = 0, val = INF;
        forn(i, 0, n) {
            if (v[i].first < val) {
                val = v[i].first;
                idx = i;
            }
        }
        v1.erase(v1.begin() + idx);
        ans = min(ans, calc_box(v1));
        debug(v1.size());

        v1 = v;
        idx = 0, val = INF;
        forn(i, 0, n) {
            if (v[i].second < val) {
                val = v[i].second;
                idx = i;
            }
        }
        v1.erase(v1.begin() + idx);
        ans = min(ans, calc_box(v1));
        debug(v1.size());

        cout << ans << ln;
    }

    int main(){
        _;
        ll t; cin >> t;
        while (t--) solve();
        return 0;
    }