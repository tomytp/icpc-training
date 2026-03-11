#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

#ifdef DEBUG
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct task {
    ll t = -1;
    ll d = -1;
    ll idx = -1;
    ll pos = INF;
    
    bool operator < (const task p) const {
        if(pos != p.pos) return pos < p.pos;
        if(d != p.d) return d < p.d;
        return idx < p.idx;
    }
};

int main() {
    _; 
    ll n; cin >> n;

    vector<task> list;
    
    forn(i,0,n){
        ll t, d; cin >> t >> d;
        list.push_back({t,d,i,INF});
    }

    vector<task> list2 = list;
    
    ll acc_tot = 0;

    sort(list.begin(), list.end());

    forn(i,0,n){
        ll acc_sum = acc_tot;
        ll min_diff = INF;
        ll best = INF;

        forn(j,0,list.size()){
            if(min_diff >= list[j].t){
                best = min(best, list[j].idx);
            }
            acc_sum += list[j].t;
            ll curr_diff = list[j].d - acc_sum;
            if(curr_diff < 0){
                cout << "*" << ln;
                return 0;
            }
            min_diff = min(curr_diff, min_diff);
        }

        forn(j,0,list.size()){
            if(list[j].idx == best){
                task t = list[j];

                list2[t.idx].pos = i;
                acc_tot += t.t;
                list.erase(list.begin() + j);
                break;
            }
        }
    }

    sort(list2.begin(), list2.end());
    forn(i,0,n) cout << list2[i].idx+1 << " ";; cout << ln; 
    return 0;
}