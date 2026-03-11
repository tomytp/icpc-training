#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

string suptop;

v64 pow2(600);

void fill_options(ll i, ll mult, v64& idxs, v64& out, v64& pow) {
    if (i == idxs.size()) {
        out.push_back(mult);
        return;
    }

    fill_options(i+1, mult, idxs, out, pow);
    fill_options(i+1, mult + pow[idxs[i]], idxs, out, pow);
}

map<ll, v64> get_bottoms(string bot) {
    ll base = 0;
    v64 idxs;
    forn(i, 0, bot.size()) {
        base *= 2;
        char c = bot[i];
        if (c == '*') {
            idxs.push_back(bot.size() - i - 1);
        } else if (c == '1') {
            base++;
        }
    }

    v64 ops;
    fill_options(0, base, idxs, ops, pow2);
    map<ll, v64> pot;
    for (auto op : ops) {
        pot[op] = v64(601);
        v64& curr = pot[op];
        curr[0] = 1;
        forn(i, 1, 601) {
            curr[i] = (2 * curr[i-1]) % op;
        }
    }
    return pot;
}

void try_all(ll i, ll mult, v64& idxs, v64& comb, ll bot, v64& pow) {
    if (i == idxs.size()) {
        debug(mult);
        if (mult % bot == 0)  {
            ll curr = 0;
            forn(j, 0, suptop.size()) {
                if (suptop[j] != '*') {
                    cout << suptop[j];
                } else {
                    cout << comb[curr];
                    curr++;
                }
            }
            cout << ln;
            exit(0);
        }
        return;
    }

    comb[i] = 0;
    try_all(i+1, mult, idxs, comb, bot, pow);
    comb[i] = 1;
    try_all(i+1, mult + pow[idxs[i]], idxs, comb, bot, pow);
}

void solve (ll bottom, v64 pots, string top) {
    ll base = 0;
    v64 idxs;
    forn(i, 0, top.size()) {
        base *= 2;
        char c = top[i];
        if (c == '*') idxs.push_back(top.size() - 1 - i);
        else if (c == '1') base++;
    }

    v64 comb(idxs.size());
    try_all(0, base, idxs, comb, bottom, pots);
}

int main(){
    _;
    pow2[0] = 1;
    forn(i, 1, 600) pow2[i] = 2 * pow2[i-1];

    string top, bot; cin >> top >> bot;
    suptop = top;

    auto dp = get_bottoms(bot);

    for (auto& [k, v] : dp) {
        solve(k, v, top);
    }

    return 0;
}