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

int main(){
    _;
    ll n, e; cin >> n >> e;
    vector<string> v(n);
    forn(i, 0, n) cin >> v[i];
    v64 mx(e);
    forn(i, 0, n) {
        ll letter = v[i][0] - 'a';
        ll count = 0;
        forn(j, 0, v[i].size()) {
            if ((ll)(v[i][j] - 'a') == letter) count++;
            else break;
        }
        if (count == (ll)v[i].size()) {
            mx[letter] = INF;
        } else {
            mx[letter] += count;
        }
    }

    ll c; ll count = INF;
    forn(i, 0, e) {
        if (mx[i] < count) {
            c = i;
            count = mx[i];
        }
    }

    if (count == INF) cout << "NO\n";
    else {
        cout << string(count+1, (char) (c + 'a')) << ln;
    }    

    return 0;
}