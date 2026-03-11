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
const ll MAXN = 400001;

v64 lp(MAXN + 1), pr;

void sieve(){
    forn(i, 2, MAXN + 1){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(ll j = 0; j < (ll)pr.size() && pr[j] * i <= MAXN; ++j){
            lp[i * pr[j]] = pr[j];
            if(pr[j] == lp[i]) break;
        }
    }
}

void factors(ll x, v64 &out){
    while(x > 1){
        ll p = (ll)lp[x];
        out.push_back(p);
        while(x % p == 0) x /= p;
    }
}

void solve(){
    ll n; cin >> n;

    v64 a(n), b(n);
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) cin >> b[i];

    unordered_map<ll,ll> minb; minb.reserve(n*2);
    bool any_even=false;
    ll odd1=INF, odd2=INF;
    forn(i,0,n){
        ll v=a[i];
        auto it=minb.find(v);
        if(it==minb.end()) minb.emplace(v,b[i]);
        else if(b[i]<it->second) it->second=b[i];
        if((v&1)==0) any_even=true;
        if(v&1){
            if(b[i]<odd1){ odd2=odd1; odd1=b[i]; }
            else if(b[i]<odd2){ odd2=b[i]; }
        }
    }

    vector<ll> vals; vals.reserve(minb.size());
    for(auto &kv:minb) vals.push_back(kv.first);

    unordered_map<ll,int> cnt; cnt.reserve(vals.size()*2);
    vector<ll> primes_present; primes_present.reserve(vals.size()*2);
    v64 fac;

    forn(i,0,(ll)vals.size()){
        fac.clear();
        factors(vals[i], fac);
        sort(fac.begin(), fac.end());
        fac.erase(unique(fac.begin(), fac.end()), fac.end());
        for(ll p: fac){
            int &c=cnt[p];
            c++;
            if(c==1) primes_present.push_back(p);
            if(c==2){ cout<<0<<ln; return; }
        }
    }

    ll best_single=INF;
    forn(k,0,(ll)primes_present.size()){
        ll p=primes_present[k], best_p=INF;
        forn(i,0,(ll)vals.size()){
            ll v=vals[i], r=v%p;
            if(r==0) continue;
            ll add=(p-r)*minb[v];
            if(add<best_p) best_p=add;
        }
        if(best_p<best_single) best_single=best_p;
    }

    ll best_pair2=INF;
    if(!any_even && odd2<INF) best_pair2=odd1+odd2;

    ll ans=min(best_single,best_pair2);
    cout << ans << ln;
}

int main(){
    _;
    sieve();
    ll t; cin >> t;
    while (t--) solve() ;
    return 0;
}