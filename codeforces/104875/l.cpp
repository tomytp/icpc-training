#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _;
    ll g, l; cin >> g >> l;
    vector<pair<string, string>> v(g-1);
    forn(i, 0, g-1) cin >> v[i].first >> v[i].second;
    string ans(l, ' ');
    v64 low(26), high(26, INF);
    vector<v64> proib(26, v64(l, 0));

    forn(i, 0, g-1) {
        v64 cnt(26);
        map<ll, ll> black;
        forn(j, 0, l) {
            ll idx = (v[i].first[j]) - 'a';
            if (v[i].second[j] == 'G') {
                ans[j] = v[i].first[j];
                cnt[idx]++;
                low[idx] = max(low[idx], cnt[idx]);
            } else if (v[i].second[j] == 'Y') {
                cnt[idx]++;
                proib[idx][j] = 1;
                low[idx] = max(low[idx], cnt[idx]);
            } else {
                proib[idx][j] = 1;
                black[idx]++;
            }
        }
        for(auto [k, v]: black) high[k] = cnt[k] - v;
    }


    return 0;
}