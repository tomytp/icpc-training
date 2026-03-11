#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

#if defined(DEBUG) || defined(debug)
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
    #define _ (void)0
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// Suffix Array - O(n log n)
//
// kasai recebe o suffix array e calcula lcp[i],
// o lcp entre s[sa[i],...,n-1] e s[sa[i+1],..,n-1]
//
// Complexidades:
// suffix_array - O(n log(n))
// kasai - O(n)

v64 suffix_array(v64 s) {
	s.push_back(0); // $ ou 0
	ll n = s.size(), N = max(n, 260ll);
	v64 sa(n), ra(n);
	forn(i, 0, n) sa[i] = i, ra[i] = s[i];

	for(ll k = 0; k < n; k ? k *= 2 : k++) {
		v64 nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
        
		forn(i, 1, N) cnt[i] += cnt[i-1];
		for(ll i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(ll i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break; 
	}
	return v64(sa.begin()+1, sa.end());
}

v64 kasai(v64 s, v64 sa) {
	ll n = s.size(), k = 0;
	v64 ra(n), lcp(n);
	forn(i, 0, n) ra[sa[i]] = i;

	for (ll i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		ll j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

int main(){
    _; ll n; cin >> n;
    v64 v(n);
    forn(i,0,n) cin >> v[i];

    v64 sa = suffix_array(v);
    v64 vec = kasai(v, sa);

    stack<p64> st;
    v64 dp(n, 0);
    dp[0] = vec[0];
    st.emplace(vec[0], 0);
    ll ans = dp[0];
    forn(i,1,n-1){
        ll prev = 0;
        while (st.size() && st.top().first >= vec[i]) st.pop();
        if (st.empty()) prev = -1;
        else prev = st.top().second;

        if(prev != -1) dp[i] = (i-prev)*vec[i] + dp[prev];
        else dp[i] = (i+1)*vec[i];

        ans += dp[i];
        st.emplace(vec[i], i);
    }

    ans *= 2;
    ans += (n*(n+1))/2;
    ll dem = n*n;
    ll d = gcd(ans, dem);
    ans /= d;
    dem /= d;
    cout << ans << "/" << dem << ln;
    return 0;
}