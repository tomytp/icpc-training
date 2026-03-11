    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll, ll> p64;
    typedef vector<ll> v64;

    #define forn(i, s, e) for (ll i = s; i < (e); i++)
    #define sz(u) ((ll) u.size())
    #define ln "\n"

    #ifdef DEBUG
    #define trace(u) u
    #define _
    #else
    #define trace(u)
    #define _ ios::sync_with_stdio(0); cin.tie(0)
    #endif

    #define debug(u) trace(cout << #u " = " << u << ln)
    #define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

    const ll INF = 0x3f3f3f3f3f3f3f3fll;

    int main() {
        _;
        ll n, i, t; cin >> n >> i >> t;
        set<p64> open, o2;
        open.emplace(i, t);

        auto test = [&](ll curi, ll curt, ll il, ll ih, ll tl, ll th){
            if(curi < il) return false;
            if(curi > ih) return false;
            if(curt < tl) return false;
            if(curt > th) return false;
            return true;
        };

        forn(j, 0, n) {
            ll il, ih, tl, th; cin >> il >> ih >> tl >> th;
            set<p64> closed;
            ll bst = 0;
            
            for (auto [mi, mt] : open) {
                bst = max(mi + mt, bst);
                if (test(mi, mt, il, ih, tl, th)) {
                    closed.emplace(mi+1, mt);
                    closed.emplace(mi, mt+1);
                    bst = max(mi+mt+1, bst);
                }
            }

            for(auto [mi, mt] : open) if (mi+mt == bst) o2.emplace(mi, mt);
            for(auto [mi, mt] : closed) if (mi+mt == bst) o2.emplace(mi, mt);
            open = move(o2);
            o2.clear();
        }

        ll ans = 0;
        for (auto [x, y] : open) ans = max(ans, x+y - i - t);
        cout << ans << ln; 

        return 0;
    }