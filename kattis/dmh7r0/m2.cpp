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

    auto passo = [&](ll cimp, ll cthi, p64 ir, p64 tr){
        if(cimp > ir.second) return false;
        if(cthi > tr.second) return false;
        if(cimp < ir.first) return false;
        if(cthi < tr.first) return false;
        return true;
    };

    forn(mask, 0, (1<<n)){
        ll currimp = imp;
        ll currthi = thi;
        ll currresp = 0;
        v64 solved;
        forn(i,0,n){
            if(passo(currimp, currthi, ir[i], tr[i])){
                currresp++;
                solved.push_back(i);
                if((mask&(1<<i)) == 0) currimp++;
                else currthi++;
            }
        }
        resp = max(resp, currresp);
        trace(
        if(currresp == 6){
            debug(bitset<10>(mask));
            debugv(solved); 
        }

        );
    }

    cout << resp << ln;
    return 0;
}