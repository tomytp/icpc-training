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
const ll MAXN = 100'008;

v64 primes;
vector<bool> is_comp(MAXN+1,false);
ll mu[MAXN+1];
ll cum_sum[MAXN+1];
vector<v64> divs(MAXN+1);

void sieve(ll n){
  	mu[1] = 1;
  	forn(i,2,n){
    if(!is_comp[i]){
    	mu[i] = -1;
    	primes.push_back(i);
    }
    
    forn(j,0,primes.size()){
		if(i*primes[j] > n) break;
		is_comp[i*primes[j]] = true;
		
		if(i % primes[j] == 0){
			mu[i*primes[j]] = 0; 
			break;
		}
		mu[i*primes[j]] = mu[i]*mu[primes[j]];    
    }
  }
}

ll func(ll idx, map<ll,ll> &cnt){
	ll resp = 0;
	for(ll div: divs[idx]){
		resp += mu[div]*cnt[div];
	}
	return resp;
}

int main(){
    _;
	sieve(MAXN);
	
	forn(i,0,MAXN+1){
		if(mu[i] == 0) continue;
		for(ll j = i; j <= MAXN; j += i){
			divs[j].push_back(i);
		}
	}

	ll n, q; cin >> n >> q;

	v64 vec(n);

	forn(i,0,n) cin >> vec[i];

	v64 c(q), d(q);

	forn(i,0,q) cin >> c[i] >> d[i];

	v64 l(n, 0), r(n, q-1), mid(n,(q-1)/2), ans(n,-2);
	vector<v64> mid_to_idx(n);

	forn(i,0,n) mid_to_idx[(q-1)/2].push_back(i);

	forn(i,0,20){
		map<ll,ll> cnt;
		forn(j,0,q){
			for(ll div: divs[c[j]]){
				cnt[div] += mu[div]*d[j];
			}
			for(ll k: mid_to_idx[j]){
				if(func(k, cnt) >= vec[k]){
					ans[k] = j;
					r[k] = mid[k]-1; 
				}else{
					l[k] = mid[k]+1;
				}
				mid[k] = (l[k] + r[k])/2;
				if(mid[k] != j) mid_to_idx[mid[k]].push_back(k);
			}
			mid_to_idx[j].clear();
		}
		if(i < 19) continue;
		for(auto [p,p2]: cnt){
			cout << p << " " << p2 << ln;
		}
		cout << ln;
	}

	forn(i,0,n) cout << ans[i] + 1 << ln;
    return 0;
}