#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
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
    _; ll n; cin >> n;
    vector<p64> v(n);
    forn(i, 0, n){
        char c;
        ll a, b; cin >> a >> c >> b;
        if((a+b)%4 == 1 || (a+b)%4 == 2) swap(a,b);
        v[i] = {a,b};
    }

    forn(i, 0, n){
        if(v[i].first == 11 && v[i].second == 11){
            cout << "error " << i+1 << ln;
            return 0;
        }
        if(i == 0) continue;
        if(v[i].first < v[i-1].first || v[i].second < v[i-1].second){
            cout << "error " << i+1 << ln;
            return 0;
        }
        if((v[i-1].first == 11 || v[i-1].second == 11) && v[i-1] != v[i]){
            cout << "error " << i+1 << ln;
            return 0;
        }
    }

    cout << "ok" << ln;
    return 0;
}
