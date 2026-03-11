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
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll l, c;
vector<v64> grid(300, v64(300));

bool check_line(){
    v64 aux(c);

    forn(i, 0, l){
        ll best = INF;
        forn(j, 0, c) best = min(best, grid[i][j]);
        forn(j, 0, c){
            if(i == 0) aux[j] = grid[i][j]-best;
            else{
                if(aux[j] != grid[i][j]-best) return false;
            }
        }
    }

    return true;
}

bool check_col(){
    v64 aux(l);

    forn(j, 0, c){
        ll best = INF;
        forn(i, 0, l) best = min(best, grid[i][j]);
        forn(i, 0, l){
            if(j == 0) aux[i] = grid[i][j]-best;
            else{
                if(aux[i] != grid[i][j]-best) return false;
            }
        }
    }

    return true;
}

ll count(v64& v, ll n){
    map<ll, ll> mp;
    forn(i, 0, n) mp[v[i]] = i;
    ll cnt = 0, ind = 0;
    for(auto p : mp){
        ll curr = v[ind];
        ll target = p.first;
        ll target_ind = p.second;

        debug(ind);
        debug(curr);
        debug(target_ind);
        debug(target); 
        if(v[ind] == target) {
            ind++;
            continue;
        }

        cnt++;
        v[ind] = target;
        mp[target] = ind;

        v[target_ind] = curr;
        mp[curr] = target_ind;

        ind++;
    }

    debug(cnt);
    return cnt;
}

ll count_line(){
    return count(grid[0], c);
}

ll count_col(){
    v64 v(l);
    forn(i, 0, l) v[i] = grid[i][0];

    return count(v, l);
}

int main() {
    _;
    cin >> l >> c;

    forn(i, 0, l){
        forn(j, 0, c){
            cin >> grid[i][j];
        }
    }

    if(check_line() && check_col()){
        cout << count_line() + count_col() << ln;
    } else{
        cout << "*" << ln;
    }

    return 0;
}