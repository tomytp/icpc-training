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
    forn(j, i, n) {
        if (v[j] != 0) return {j, v[j]};
    }
    return {INF, INF};
}

p64 fb(ll i, v64& v) {
    for (ll j = i; j >= 0; j--) {
        if (v[j] != 0) return {j, v[j]};
    }
    return {INF, INF};
}

bool valid(v64& ans, v64& original) {
    forn(i, 0, n) if (ans[i] != original[i] && original[i] != 0) return false;
    return true;
}

int main(){
    _;
    cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    v64 original = v;

    ll l = 0, r = n-1;
    p64 nl = ff(l, v), nr = fb(r, v);

    forn(i, 1, n+1) {
        if (v[l] == i) {
            l++;
            continue;
        }

        if (v[r] == i) {
            r--;
            continue;
        }

        if (v[l] != 0 && v[r] == 0) {
            v[r] = i;
            r--;
            continue;
        }

        if (v[r] != 0 && v[l] == 0) {
            v[l] = i;
            l++;
            continue;
        }

        if (nl.first <= l) nl = ff(l, v);
        if (nr.first >= r) nr = fb(r, v);

        if (nl == nr) {
            if (abs(l - nl.first) < abs(r - nr.first)) v[l++] = i;
            else v[r--] = i;
            continue;
        }

        if (nl.second < nr.second) v[l++] = i;
        else v[r--] = i;
    }

    if (!valid(v, original)) {
        cout << "*\n";
        return 0;
    }

    forn(i, 0, n) cout << v[i] << " \n"[i==n-1];
    return 0;
}