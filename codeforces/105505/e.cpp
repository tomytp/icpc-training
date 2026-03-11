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
ll n;

p64 ff(ll i, v64& v) {
    forn(j, i, n)
        if (v[j] != 0) 
            return {j, v[j]};
    return {INF, INF};
}

p64 fb(ll i, v64& v) {
    for(ll j = i; j >=0; j--)
        if (v[j] != 0) 
            return {j, v[j]};
    return {INF, INF};
}

bool is_valid(v64& v, v64& org, ll peak) {
    forn(i, 0, n) 
        if (org[i] != 0 && org[i] != v[i]) 
            return false;

    forn(i, peak+1, n) 
        if (v[i] > v[i-1])
            return false;
        
    forn(i, 1, peak + 1)
        if (v[i] < v[i-1])
            return false;
    
    return true;
}

int main(){
    _;
    cin >> n;
    v64 v(n), org(n); 
    forn(i, 0, n) cin >> v[i], org[i] = v[i];
    
    ll l = 0, r = n-1;
    p64 nl = ff(l, v);
    p64 nr = fb(r, v);
    ll peak = 0;
    forn(i, 1, n+1) {
        if (i == n) peak = l;
        if (v[l] == i) {
            l++;
            continue;
        }

        if (v[r] == i) {
            r--;
            continue;
        }

        if (v[l] != 0 && v[r] == 0) {
            v[r--] = i;
            continue;
        }

        if (v[r] != 0 && v[l] == 0) {
            v[l++] = i;
            continue;
        }

        if (nl.first <= l) nl = ff(l, v);
        if (nr.first >= r) nr = fb(r, v);

        if (nl.second == nr.second) {
            if (abs(l - nl.first) > abs(r - nr.first)) v[r--] = i;
            else v[l++] = i;
            continue;
        }

        if (nl.second > nr.second) v[r--] = i;
        else v[l++] = i;
    }

    if (!is_valid(v, org, peak)) {
        cout << "*\n";
        return 0;
    }

    forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    return 0;
}