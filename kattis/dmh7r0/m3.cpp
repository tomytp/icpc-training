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
    _;
    ll n, imp, thi; cin >> n >> imp >> thi;
    vector<p64> ir, tr;

    forn(j, 0, n) {
        ll il, ih, tl, th; cin >> il >> ih >> tl >> th;
        ir.emplace_back(il, ih);
        tr.emplace_back(tl, th);
    }

    ll resp = 0;

    auto corrige = [&](ll cimp, ll cthi, p64 ir, p64 tr){
        p64 ret = {INF,INF};
        if(cimp > ir.second) return ret;
        if(cthi > tr.second) return ret;
        ret.first = max(0ll, ir.first-cimp);
        ret.second = max(0ll, tr.first-cthi);
        return ret;
    };

    forn(mask, 0, (1<<n)){
        ll currimp = imp;
        ll currthi = thi;
        ll currresp = 0;
        ll x = 0;
        bool f = false;

        forn(i,0,n){
            if((mask&(1<<i)) == 0) continue;

            currresp++;
            p64 p = corrige(currimp, currthi, ir[i], tr[i]);
            ll t = p.first + p.second;

            if(t > x){ 
                f = true;
                break;
            }
            x -= t;
            currimp += p.first;
            currthi += p.second;
            x++; 
        } 
        if(f) continue;
        resp = max(resp, currresp);
        if(currresp == 4) debug(bitset<10>(mask));
    }

    cout << resp << ln;
    return 0;
}