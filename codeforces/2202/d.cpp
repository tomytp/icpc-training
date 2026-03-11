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

void build(ll n) {
    set<ll> zero, um, dois;

    forn(i, 2, n) zero.insert(i);
    um.insert(0);
    um.insert(1);
    cout << "1 2 ";
    forn(i, 1, n) {
        if (sz(zero)) {
            ll v = *zero.begin();
            ll v2 = *um.begin();
            zero.erase(zero.begin());
            um.erase(um.begin());
            um.insert(v);
            dois.insert(v2);
            cout << v+1 << " " << v2+1 << " ";
            continue;
        }
        ll v = *um.begin();
        ll v2 = *(++um.begin());
        cout << v+1 << " " << v2+1 << " ";
    }
}

void solve() {
    ll n, k; cin >> n >> k;
    if (n > k) {
        cout << "NO\n";
        return; 
    }
    if (n == 1) {
        if (k != 1) {
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            cout << "1 1\n";
            return;
        }
    }
    if (n == 2) {
        if (k == 2) {
            cout << "YES\n";
            cout << "1 1 2 2\n";
            return;
        } else if (k == 3) {
            cout << "YES\n";
            cout << "1 2 1 2\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (k > (n*2 - 1)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (n == k) {
        forn(i, 1, n+1) {
            cout << i << " " << i << " ";
        }
        cout << ln;
        return;
    }

    forn(i, 2, n+1) {
        ll after = (n-i);
        ll val = (2*i-1) + after;
        if (k == val) {
            build(i);
            forn(j, i+1, n+1) {
                cout << j << " " << j << " ";
            }
            cout << ln;
            return;
        }
    }

}

int main() {
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}
