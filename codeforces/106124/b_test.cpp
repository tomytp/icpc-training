#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({cout << #v": "; for (auto x : v) cout<< x << " "; cout << ln;})
#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll MAXMAX = 905;

#define N 105

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

int dp(ll i, ll th, ll hg, ll state, ll n, ll w, ll h, ll tot, vector<ll> &hs, vector<ll> &ts, vector<vector<vector<vector<ll>>>> &DP) {
  if (i == n) {
    if (state != 3) return 0;
    if (w - th < hg) return 0;
    if (h < tot - th) return 0;
    if (th > w) return 0;
    return 1;
  }

  if (DP[i][th][hg][state] != -1) return DP[i][th][hg][state];

  if (hs[i] > h) {
    return DP[i][th][hg][state] =
               dp(i + 1, th, max(hg, hs[i]), state | (1 << 1), n, w, h, tot, hs, ts, DP);
  }

  return DP[i][th][hg][state] =
             max(dp(i + 1, th, max(hg, hs[i]), state | (1 << 1), n, w, h, tot, hs, ts, DP),
                 dp(i + 1, th + ts[i], hg, state | (1 << 0), n, w, h, tot, hs, ts, DP));
}

void rec(ll i, ll th, ll hg, ll state, ll n, ll w, ll h, ll tot, vector<ll> &hs, vector<ll> &ts, vector<vector<vector<vector<ll>>>> &DP, vector<vector<ll>>& ans) {
  if (i == n) {
    return;
  }

  if (hs[i] > h) {
    ans[1].push_back(i);
    rec(i + 1, th, max(hg, hs[i]), state | (1 << 1), n, w, h, tot, hs, ts, DP, ans);
    return;
  }

  if (dp(i + 1, th, max(hg, hs[i]), state | (1 << 1), n, w, h, tot, hs, ts, DP) >
      dp(i + 1, th + ts[i], hg, state | (1 << 0), n, w, h, tot, hs, ts, DP)) {
    ans[1].push_back(i);
    rec(i + 1, th, max(hg, hs[i]), state | (1 << 1), n, w, h, tot, hs, ts, DP, ans);
    return;
  }

  ans[0].push_back(i);
  rec(i + 1, th + ts[i], hg, state | (1 << 0), n, w, h, tot, hs, ts, DP, ans);
}

bool test_possib(ll n, ll h, ll w, vector<ll>& hs, vector<ll>& ts) {
    ll tot;
    for (int i = 0; i < n; i++) {
        tot += ts[i];
    }

    vector<vector<ll>> ans(2);
    vector<vector<vector<vector<ll>>>> DP(N+1, vector<vector<vector<ll>>>(610, vector<vector<ll>>(500 , vector<ll>(4, -1))));
    
    if (dp(0, 0, 0, 0, n, w, h, tot, hs, ts, DP)) {
        rec(0, 0, 0, 0, n, w, h, tot, hs, ts, DP,ans);
        if (ans[0].empty() || ans[1].empty()) {
        return false;
        }
        return true;
    } else {
        return false;
    }
}

bool knapsack(vector<p64>& books, ll idx, ll c1, ll c2, set<ll>& ans){
    v64 sums(MAXMAX, -1);
    ll tot = 0;
    forn(i,0,idx){
        tot += books[i].second;
        for(ll j = MAXMAX-1; j >= 0; j--){
            if(j+ books[i].second >= MAXMAX) continue;
            if(sums[j] == -1) continue;
            if(sums[j+ books[i].second] != -1) continue;
            sums[j+ books[i].second] = i;
        }

        if(sums[books[i].second] != -1) continue;
        sums[books[i].second] = i;
    }

    forn(i, max(tot-c2, 1ll), c1+1){
        if(sums[i] != -1){
            ll x = i;
            while(x > 0){
                ans.insert(sums[x]);
                x -= books[sums[x]].second;
            }
            return true;
        }

    }
    return false;
}

bool solve(ll n, ll h, ll w, vector<ll>& hs, vector<ll>& ts, vector<ll>& up, vector<ll>& stacked){
    vector<pair<p64, ll>> books_input(n);
    forn(i,0,n){
        books_input[i].first.first = hs[i];
        books_input[i].first.second = ts[i];
        books_input[i].second = i;
    }

    sort(books_input.begin(), books_input.end());
    v64 mpidx(n);
    vector<p64> books(n);

    forn(i,0,n){
        books[i] = books_input[i].first;
        mpidx[i] = books_input[i].second;
    }

    ll altura_pilha_deitada = -1;
    // ll altura_pilha_pe = 0;
    ll largura_pilha_deitada = 0;
    ll largura_pilha_pe = 0;


    ll curr_idx = n-1;
    
    set<ll> ans;

    for(; curr_idx >= 0; curr_idx--){
        if(books[curr_idx].first > h){
            largura_pilha_deitada = max(largura_pilha_deitada, books[curr_idx].first);
            altura_pilha_deitada += books[curr_idx].second;
        }else{
            break;
        }
    }

    bool bom = false;
    if(altura_pilha_deitada != -1){
        ll c1 = w - largura_pilha_deitada;
        ll c2 = h - altura_pilha_deitada;
        if(knapsack(books, curr_idx+1, c1, c2, ans)) bom = true;
    }

    for(; curr_idx >= 0; curr_idx--){
        if(bom) break;

        ll c1 = w - (max(largura_pilha_deitada, books[curr_idx].first) + largura_pilha_pe);
        ll c2 = h - (altura_pilha_deitada +  books[curr_idx].second);
        if(c1 < 0 || c2 < 0) continue;

        if(knapsack(books, curr_idx, c1, c2, ans)){
            bom = true;
            break;
        }

        largura_pilha_pe += books[curr_idx].second;
        ans.insert(curr_idx);
    }

    if(!bom){
        return false;
    }else{
        for(ll x : ans) up.push_back(mpidx[x]+1);

        vector<p64> aux;
        forn(x,0,n) if(ans.count(x) == 0){
            aux.emplace_back(books[x].first, x);
        }
        sort(aux.rbegin(), aux.rend());

        for(auto p: aux) stacked.push_back(mpidx[p.second]+1);
        return true;
    }
}

bool test(ll n, ll h, ll w, vector<ll>& hs, vector<ll>& ts, vector<ll>& up, vector<ll>& stacked) {
    ll width_min = 0;
    ll best_h = 0;
    for(auto x : up){
        width_min += ts[x];
        best_h = max(best_h, hs[x]);
    }

    ll height_min = 0;
    ll best_w = 0;
    for(auto x : stacked){
        height_min +=ts[x];
        best_w = max(best_w, hs[x]);
    }

    height_min = max(height_min, best_h);
    width_min += best_w;

    return (width_min <= w) && (height_min <= h) && (best_h > 0) && (best_w > 0);
}

int main(){
    _;
    ll n = 3, h = 100, w = 100;
    while(true){
        vector<ll> hs(n), ts(n), up, stacked;
        forn(i, 0, n) {
            hs[i] = uniform(1, 100);
            ts[i] = uniform(1, 100);
        }
        bool s1, s2, s3;
        s1 = solve(n, h, w, hs, ts, up, stacked);
        s2 = test_possib(n, h, w, hs, ts);
        if(s1) s3 = test(n, h, w, hs, ts, up, stacked);

        if((s1 != s2) || (s1 && !s3)){
            debugv(hs);
            debugv(ts);
            break;
        }
    }
}