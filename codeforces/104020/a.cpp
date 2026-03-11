#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
typedef long double ld;

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
ll n, k, x;
v64 v;
ll tot = 0;

ld solve(ll q) {
    if (q == 0) {
        return fabs(x- ((ld) tot / n));
    }

    ld bst = 2e18;
    if (q == 1) {
        forn(i, 0, n) bst = min(bst, fabsl((ld) x - ((ld) (tot-v[i])/(ld)(n-1))));
    }

    if (q == 2) {
        forn(i, 0, n) {
            forn(j, i+1, n) {
                bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i] - v[j]) / (ld) (n-2))));
            }
        }
    }

    if (q == 3) {
        ld tgt = x * (n-3);
        forn(i, 0, n-2) {
            forn(j, i+1, n-1) {
                ld exp = tot - tgt - v[i] - v[j];

                auto it = lower_bound(v.begin() + j+1, v.end(), exp);
                ll idx = it - v.begin();
                if (idx-1 > j && idx-1 < n) bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i]-v[j]-v[idx-1])/(ld) (n-3))));
                if (idx > j && idx < n) bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i]-v[j]-v[idx])/(ld) (n-3))));
                if (idx+1 > j && idx+1 < n) bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i]-v[j]-v[idx+1])/(ld) (n-3))));
            }
        }
    } 

    if (q == 4) {
        ld tgt = x * (n-4);
        set<ll> open;
        open.insert(v[n-1] + v[n-2]);
        for (ll i = n-3; i >= 0; i--) {
            forn(j, 0, i) {
                ld exp = tot - tgt - v[i] - v[j];
                auto it = open.lower_bound(exp);
                if (it != open.begin()) it--;
                if (it != open.end()) bst = min(bst, fabsl((ld)x - ((ld)((tot-v[i]-v[j]-*it)/ (ld)(n-4))))), it++;
                if (it != open.end()) bst = min(bst, fabsl((ld)x - ((ld)((tot-v[i]-v[j]-*it)/ (ld)(n-4))))), it++;
                if (it != open.end()) bst = min(bst, fabsl((ld)x - ((ld)((tot-v[i]-v[j]-*it)/ (ld)(n-4))))), it++;
            }
            forn(j, i+1, n) {
                open.insert(v[i] + v[j]);
            }
        } 
    }

    return bst;
}

int main() {
    _;
    cin >> n >> k >> x;
    v.resize(n);
    forn(i, 0, n) cin >> v[i], tot += v[i];
    sort(v.begin(), v.end());

    ld bst = 2e18;

    forn(i, 0, k+1) {
        bst = min(bst, solve(i));
        debug(i);
        debug(bst);
    }
 
    cout << fixed << setprecision(20) << bst << ln;
    
    return 0;
}