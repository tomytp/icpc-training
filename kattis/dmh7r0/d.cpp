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
    _; ll n, m; cin >> n >> m;
    v64 a(n), b(m), a_inv(n);
    forn(i, 0, n){
        cin >> a[i];
        a[i]--;
        a_inv[a[i]] = i;
    }
    forn(i, 0, m){
        cin >> b[i];
        b[i]--;
    }

    ll last = a_inv[b[0]];
    bool deu_ruim = false;
    forn(i, 0, m){
        if(a[(last+i)%n] != b[i]){
            deu_ruim = true;
            break;
        }
    }

    if(!deu_ruim){
        cout << 1 << ln;
        return 0;
    }

    deu_ruim = false;
    forn(i, 0, m){
        if(a[(last-i+n)%n] != b[i]){
            deu_ruim = true;
            break;
        }
    }

    if(deu_ruim) cout << 0 << ln;
    else cout << 1 << ln;
    
    return 0;
}