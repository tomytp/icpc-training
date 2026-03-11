#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 pi(v64& s){
    v64 p(sz(s));
    for(ll i = 1, j = 0; i < sz(s); i++) {
        while(j && s[j] != s[i]) j = p[j-1];
        if(s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

v64 match(v64& pat, v64& s){
    v64 p = pi(pat), match;
    for(ll i = 0, j = 0; i< sz(s); i++){
        while(j && pat[j] != s[i]) j = p[j-1];
        if(pat[j] == s[i]) j++;
        if(j == sz(pat)) match.push_back(i-j+1), j = p[j-1];
    }
    return match;
}

int main() {
    _; ll n, m; cin >> n >> m;
    v64 v1(n), v2(m), pat(n-1), s(m-1);
    forn(i, 0, n) cin >> v1[i];
    forn(i, 0, m) cin >> v2[i];
    if(n == 1){
        cout << m << ln;
        return 0;
    }

    forn(i, 0, n-1){
        pat[i] = v1[i+1]-v1[i];
    }

    forn(i, 0, m-1){
        s[i] = v2[i+1] - v2[i];
    }

    v64 mat = match(pat, s);

    cout << sz(mat) << ln;
    // forn(i, 0, sz(pat)) cout << pat[i] << " ";
    // cout << ln;
    // forn(i, 0, sz(s)) cout << s[i] << " ";
    // cout << ln;
    // forn(i, 0, sz(mat)) cout << mat[i] << " ";
    // cout << ln;

    return 0;
}