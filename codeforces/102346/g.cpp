#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<double>> m;

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

bool melhora(v64& perm, ll n) {
    forn(i, 0, n) {
        forn(j, 0, i) {
            if (m[i][perm[i]] + m[j][perm[j]] > m[i][perm[j]] + m[j][perm[i]]) {
                swap(perm[i], perm[j]);
                return true;
            }
        }
    }
    return false;
}

v64 rand_perm(ll n) {
    v64 perm(n);
    set<p64> c;
    forn(i, 0, n) {
        c.emplace(uniform(1, 1000000000), i);
    }
    ll i = 0;
    for(auto& [a, b] : c) {
        perm[i] = b;
        i++;

    }
    return perm;
}

int main() {
    _;
    ll n; cin >> n;
    m.resize(n, vector<double>(n));
    forn(i, 0, n)
    forn(j, 0, n) {
        ll a; cin >> a;
        m[i][j] = log(a);
    }

    ll best = 0;
    v64 best_perm;
    ll iterations = 100;
    ll tries = 100;

    forn(xxx, 0 ,tries) {
        v64 perm = rand_perm(n);
        forn(yyy, 0, iterations) {
            if (melhora(perm, n)) break;
        }
        double sum = 0;
        forn(i, 0, n) sum += m[i][perm[i]];
        if (sum > best) {
            best = sum;
            swap(perm, best_perm);
        }
    }

    forn(i, 0, n) cout << best_perm[i] + 1 << " \n"[i==n-1];

    return 0;
}