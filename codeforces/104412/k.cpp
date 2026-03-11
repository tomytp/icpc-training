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
        ll n, k;
        cin >> n >> k;
        k--;
        vector<v64> mat(n, v64(n));

        forn(i,0,n)
        forn(j,0,n)
            cin >> mat[i][j];

        ll resp = 0;

        forn(i,0,n-k){
            forn(j,0,n-k){
                ll val = mat[i][j];
                if(mat[i][j+k] != val) continue;
                if(mat[i+k][j] != val) continue;
                if(mat[i+k][j+k] != val) continue;
                resp++;
            }
        }
        cout << resp << ln;

        return 0;
    }