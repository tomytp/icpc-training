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

int main() {
    _;
    ll n, k; cin >> n >> k;
    k = min(n,k);

    v64 vec(n);
    v64 tipo(n);
    vector<vector<p64>> dp(k+1, vector<p64>(n, {-1, -1}));
    forn(i,0,n) cin >> vec[i];
    forn(i,0,n) cin >> tipo[i];

    forn(l, 0, n) {
        if (tipo[l] == 1) {
            dp[1][l] = {vec[l], 0}; 
        } else {
            dp[1][l] = {-1, -1};
        }
    }

    ll resp = 0;
    forn(tam, 2, k+1) {
        forn(l, 0, n) {
            if (dp[tam-1][l].first != -1) {
                if (tipo[((l+tam-1)%n)] == 1) {
                    dp[tam][l] = {dp[tam-1][l].first + vec[((l+tam-1)%n)], dp[tam-1][l].second};
                } else if (dp[tam-1][l].first >= vec[((l+tam-1)%n)]) {
                    dp[tam][l] = {dp[tam-1][l].first - vec[((l+tam-1)%n)], dp[tam-1][l].second + vec[((l+tam-1)%n)]};
                    resp = max(resp, dp[tam][l].second);
                }
            } 
            
            if (dp[tam-1][((l+1)%n)].first != -1) {
                if (tipo[l] == 1) {
                    dp[tam][l] = {dp[tam-1][((l+1)%n)].first + vec[l], dp[tam-1][((l+1)%n)].second};
                } else if (dp[tam-1][((l+1)%n)].first >= vec[l]) {
                    dp[tam][l] = {dp[tam-1][((l+1)%n)].first - vec[l], dp[tam-1][((l+1)%n)].second + vec[l]};
                    resp = max(resp, dp[tam][l].second);
                }
            }
        }
    }

    cout << resp << ln;


    return 0;
}