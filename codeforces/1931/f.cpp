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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}


void solve() {
    ll n, k; cin >> n >> k;
    vector<v64> v(k, v64(n));
    forn(i, 0, k) {
        forn(j, 0, n) cin >> v[i][j];
    }

    if (k == 1) {
        cout << "YES" << ln;
        return;
    }

    if (k > 2) {
        while (true) {
            if (v[0][n-1] == v[1][0] && v[1][n-1] == v[0][0]) {
                swap(v[uniform(0,1)], v[uniform(0,k-1)]);
                continue;
            }

            if (v[0][1] == v[1][0] && v[1][1] == v[0][0]) {
                swap(v[uniform(0,1)], v[uniform(0,k-1)]);
                continue;
            }
            break;
        }
    }
      
    auto merge = [&](ll i1, ll i2, bool swp) {
        v64 res;
        ll p1 = 1, p2 = 1;
        while (p1 < n && p2 < n) {
            if (v[i1][p1] == v[i2][p2]) {
                res.push_back(v[i1][p1]);
                p1++; p2++;
            } 
            else if (p1 + 1 < n && v[i1][p1+1] == v[i2][p2]) {
                res.push_back(v[i1][p1]);
                p1++;
            }
            else if (p2 + 1 < n && v[i1][p1] == v[i2][p2+1]) {
                res.push_back(v[i2][p2]);
                p2++;
            }
            else {
                if (swp) {
                     res.push_back(v[i2][p2]); p2++;
                } else {
                     res.push_back(v[i1][p1]); p1++;
                }
            }
        }
        while(p1 < n) res.push_back(v[i1][p1++]);
        while(p2 < n) res.push_back(v[i2][p2++]);
        return res;
    };

    auto check = [&](v64& cand, v64& gaba) {
        ll curr = 0;
        forn(j, 1, n) {
            if (gaba[curr] == cand[0]) {
                curr++;
            }
            if (cand[j] != gaba[curr]) {
                debugv(cand);
                return false;
            }
            curr++;
        }
        return true;
    };

    v64 gaba1 = merge(0, 1, false);
    v64 gaba2 = merge(0, 1, true);


    bool gaba11 = true;
    bool gaba22 = true;

    debugv(gaba1);
    debugv(gaba2);


    forn(i, 0, k) {
        gaba11 &= check(v[i], gaba1);
        gaba22 &= check(v[i], gaba2);
    }
    if (gaba11 || gaba22) cout << "YES" << ln;
    else cout << "NO" << ln;
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}