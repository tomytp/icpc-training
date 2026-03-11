
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t lll;
typedef lll ull;
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

ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}

bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
	    s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}


int main(){
    
    forn(i,1,5){
    forn(j,0,7){
        lll val = 49;
        lll pot = 100;
        forn(t,1,j){
            val += (0*pot);
            pot = (pot*10);
        }
        forn(t,1,i){
            val += (6*pot);
            pot = (pot*10);
        }

        cout << (ll)val << " ";
        if(isPrime(val)){
            cout << "PRIMO" << ln;
        }else{
            cout << "Ok" << ln;
        }
        // if(pot%7 == 0){
        //     cout << " FF" << ln;
        // }else{
        //     cout << " ok" << ln;
        // }
    }
    }
}