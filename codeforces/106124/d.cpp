#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
const ld eps = 0.00000001;

ld dist(pair<ld,ld> p1, pair<ld,ld> p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

int main() {
    _; ll n; cin >> n;
    vector<pair<ld,ld>> v(n);
    forn(i, 0, n){
        ll a, b;
        cin >> a >> b;
        v[i] = {(ld)a,(ld)b};
    }

    ld best = 0, best_ind;
    forn(i, 0, n){
        ld curr = dist(v[0], v[i]);
        if(curr > best + eps){
            best = curr;
            best_ind = i;
        }
    }

    vector<pair<ld, ll>> ord;
    forn(i, 0, n) ord.push_back({dist(v[best_ind], v[i]), i});
    sort(ord.begin(), ord.end());

    ld sum = 0;
    forn(i, 0, n-1){
        pair<ll, ll> curr = v[ord[i].second], nxt = v[ord[i+1].second];
        sum += dist(curr, nxt);
    }
    cout << fixed << setprecision(10) << sum << ln;
}