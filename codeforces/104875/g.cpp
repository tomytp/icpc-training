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

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}


ll MX = 100;

ll ask(string s) {
    cout << "? " << s << endl;
    ll x; cin >> x;
    return x;
}

void burro() {
    ask("flip");
    ll aux = 0;
    ll ans = 0;
    while (!aux) {
        aux = ask("right");
        ans++;
    }
    cout << "! " << ans << endl;
}

bool comp(vector<bool> pat, vector<bool> cand) {
    if (sz(pat) > sz(cand)) return false;

    ll diff = sz(cand) - sz(pat);
    forn(i, 0, sz(pat)) {
        if (pat[i] != cand[i+diff]) return false;
    } 
    return true;
}

void inteligente() {
    vector<bool> pat(MX);
    forn(i, 0, MX) pat[i] = uniform(0,1);
    pat[3] = 1;
    ll aux;
    forn(i, 0, MX) {
        if (pat[i]) ask("flip");
        aux = ask("right");
    }
    vector<bool> v;
    v.push_back(aux);
    ll resp = 1;
    while (!comp(pat, v)) {
        aux = ask("right");
        v.push_back(aux);
        resp++;
    }
    cout << "! " << resp << endl;
}

int main() {
    _;
    ll aux; cin >> aux;
    vector<bool> v;
    if (aux == 0) ask("flip");
    forn(i, 0, MX) {
        ll cur = ask("right");
        if (cur) ask("flip");
    }
    forn(i, 0, MX) aux = ask("left");
    if (aux == 0) {
        burro();
    } else {
        ask("flip");
        inteligente();
    }

    return 0;
}