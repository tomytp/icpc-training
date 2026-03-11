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

v64 pi(string& s) {
	v64 p(s.size());
	for (ll i = 1, j = 0; i < (ll) s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

v64 match(string& pat, string& s) {
	v64 p = pi(pat), match;
	for (ll i = 0, j = 0; i < (ll) s.size(); i++) {
		while (j and pat[j] != s[i]) j = p[j-1];
		if (pat[j] == s[i]) j++;
		if (j == pat.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}
	
struct KMPaut : vector<v64> {
	KMPaut(){}
	KMPaut (string& s) : vector<v64>(26, v64(s.size()+1)) {
		v64 p = pi(s);
		auto& aut = *this;
		aut[s[0]-'a'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'a' == c ? i+1 : aut[c][p[i-1]];
	}
};


int main(){
    _; string s; cin >> s;
    KMPaut k(s);

    for(auto x : k){
        for(auto y : x) cout << y << " ";
        cout << ln;
    }
    return 0;
}