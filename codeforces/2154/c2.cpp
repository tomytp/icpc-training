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

#include <bits/extc++.h> 

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};

const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 200001;

static int lp[MAXN+2], primes_list[MAXN+2], pcnt;
static ll best1_cost[MAXN+2], best2_cost[MAXN+2];
static int best1_idx[MAXN+2], best2_idx[MAXN+2];
static bool first_time = true;

void sieve(){
    for(int i=2;i<=MAXN+1;i++){
        if(!lp[i]) lp[i]=i, primes_list[pcnt++]=i;
        for(int j=0;j<pcnt && 1LL*primes_list[j]*i<=MAXN+1; j++){
            lp[primes_list[j]*i]=primes_list[j];
            if(primes_list[j]==lp[i]) break;
        }
    }
}

inline void factor_distinct(int x, v64 &out){
    while(x>1){
        int p = lp[x];
        out.push_back(p);
        while(x%p==0) x/=p;
    }
}

inline void ensure_init(int p, v64 &touched){
    if(best1_idx[p]==-2){
        touched.push_back(p);
        best1_cost[p]=INF; best2_cost[p]=INF;
        best1_idx[p]=-1;   best2_idx[p]=-1;
    }
}

inline void upd_prime(int p, ll cost, int idx){
    if(idx==best1_idx[p]){
        if(cost<best1_cost[p]) best1_cost[p]=cost;
        return;
    }
    if(cost<best1_cost[p]){
        best2_cost[p]=best1_cost[p];
        best2_idx[p]=best1_idx[p];
        best1_cost[p]=cost;
        best1_idx[p]=idx;
    }else if(idx!=best1_idx[p] && cost<best2_cost[p]){
        best2_cost[p]=cost;
        best2_idx[p]=idx;
    }
}

void solve(){
    int n; 
    cin>>n;
    vector<int> a(n); 
    vector<ll> b(n);
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) cin>>b[i];

    if(first_time){
        for(int p=0;p<=MAXN+1;p++){
            best1_idx[p]=-2; best2_idx[p]=-2;
            best1_cost[p]=INF; best2_cost[p]=INF;
        }
        first_time=false;
    }

    v64 touched; touched.reserve(1024);
    v64 fac; fac.reserve(16);

    forn(i,0,n){
        fac.clear();
        factor_distinct(a[i], fac);
        for(int p: fac){
            ensure_init(p, touched);
            upd_prime(p, 0, i);
        }
        fac.clear();
        factor_distinct(a[i]+1, fac);
        for(int p: fac){
            ensure_init(p, touched);
            upd_prime(p, b[i], i);
        }
    }

    ll ans = INF;
    for(int p: touched){
        if(best2_idx[p]!=-1) ans = min(ans, best1_cost[p] + best2_cost[p]);
        best1_idx[p]=-2; best2_idx[p]=-2;
        best1_cost[p]=INF; best2_cost[p]=INF;
    }

    cout<<ans<<ln;
}



int main(){
    _;
    sieve();
    ll t; cin >> t;
    while (t--) solve() ;
    return 0;
}