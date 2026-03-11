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
        forn(i, 0, n) {
            forn(j, i+1, n) {
                forn(r, j+1, n) {
                    bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i] - v[j] - v[r]) / (ld) (n-3))));
                }
            }
        }
    }

    if (q == 4) {
        forn(i, 0, n) {
            forn(j, i+1, n) {
                forn(r, j+1, n) {
                   forn(p, r+1, n) {
                        bst = min(bst, fabsl((ld)x - ((ld)(tot - v[i] - v[j] - v[r] - v[p]) / (ld) (n-4))));
                    }
                }
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
    }

    cout << fixed << setprecision(20) << bst << ln;
    
    return 0;
}