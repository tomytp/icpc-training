#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct tap {
    ll t, a, b, id;

    bool operator <(const tap o) const {
        if (t != o.t) return t < o.t;
        else return id < o.id; 
    }
};

int main(){
    _;
    ll k; cin >> k;
    vector<tap> v(k);

    ll mn_flow = 0, mx_flow = 0;
    forn(i, 0, k) {
        cin >> v[i].t >> v[i].a >> v[i].b;
        mn_flow += v[i].a;
        mx_flow += v[i].b;
        v[i].id = i;
    }
    sort(v.begin(), v.end());

    ll q; cin >> q;
    while (q--) {
        ll temp, flow; cin >> temp >> flow;
        if (flow < mn_flow || flow > mx_flow) {
            cout << "no" << ln;
            continue;
        }

        v64 qtd(k);
        ll to_use = flow - mn_flow;
        forn(i, 0, k) {
            qtd[i] = v[i].a;
            if (to_use == 0) continue;
            ll rest = v[i].b - v[i].a;
            if (rest > to_use) {
                qtd[i] += to_use;
                to_use = 0;
                continue;
            } else {
                qtd[i] += rest;
                to_use -= rest;
            }
        }
        ll nom = 0;
        ll denom = accumulate(qtd.begin(), qtd.end(), 0);
        forn(i, 0, k) nom += qtd[i] * v[i].t;
        ll lb;
        if (nom % denom == 0) {
            lb = nom / denom;
        } else {
            lb = (nom/denom) + 1;
        }

        qtd.assign(k, 0);
        to_use = flow - mn_flow;
        for(ll i = k-1; i >= 0; i--) {
            qtd[i] = v[i].a;
            if (to_use == 0) continue;
            ll rest = v[i].b - v[i].a;
            if (rest > to_use) {
                qtd[i] += to_use;
                to_use = 0;
                continue;;
            } else {
                qtd[i] += rest;
                to_use -= rest;
            }
        }
        nom = 0;
        denom = accumulate(qtd.begin(), qtd.end(), 0);
        forn(i, 0, k) nom += qtd[i] * v[i].t;
        ll ub = nom / denom;
        debug(temp);
        debug(lb);
        debug(ub);
        if (temp >= lb && temp <= ub) {
            cout << "yes" << ln;
        } else {
            cout << "no" << ln;
        }
    }


    return 0;
}