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
const ll MOD = 998244353;
const ll MAXN = 101;
// 100*100*16*16*2 = 5'120'000


ll pot2[MAXN];
ll dp[MAXN][MAXN][17][17][2];
ll k;
string w; 

vector<vector<string>> lista = {
    {},
    {"0", "1"},
    { "00", "01", "10", "11"},
    { "000", "001", "010", "011", "100", "101", "110", "111"}
};

inline ll sum(ll a, ll b){
    a += b;
    return (a > MOD ? a - MOD : a);
}

void prep(){
    pot2[0] = 1;
    forn(i,1,MAXN){
        pot2[i] = sum(pot2[i-1], pot2[i-1]);
    }
}

ll convert(string& s){
    ll pot = 1;
    ll ans = 0;
    for(char c: s){
        ans += (c-'0')*pot;
        pot *= 2;
    }
    return ans;
}

ll rec(ll n, ll m, string sufn, string sufm, bool found){
    if(sufn.size() > k) sufn.pop_back();
    if(sufm.size() > k) sufm.pop_back();

    ll idxn = convert(sufn);
    ll idxm = convert(sufm);
    ll ans = 0;

    if(dp[n][m][idxn][idxm][found] != -1) return dp[n][m][idxn][idxm][found];

    debug(n);
    debug(m);
    debug(sufn);
    debug(sufm);
    debug(found);
    cout << ln;
    if(n < k){
        if(found){ 
            debug(ans);
            return dp[n][m][idxn][idxm][found] = 0;
        }else{
            ans = pot2[(m-k >= 0 ? m-k : 0)];
            debug(ans);
            return dp[n][m][idxn][idxm][found] = ans;
        }
    }
    if(m < k){
        if(found){
            debug(ans);
            return dp[n][m][idxn][idxm][found] = 0;
        }else{
            ans = pot2[(n-k >= 0 ? n-k : 0)];
            debug(ans);
            return dp[n][m][idxn][idxm][found] = ans;
        }
    }


    if(sufn == sufm){
        string sn = "0"+sufn;
        string sm = "1"+sufm;
        bool lcfound = sufn == w;
        
        if(lcfound && !found) return debug(ans), dp[n][m][idxn][idxm][found] = 0;

        if(!lcfound){
            ans = sum(ans, rec(n-1,m-1, sn, sm, found));
            sn[0] = '1';
            sm[0] = '0';
            ans = sum(ans, rec(n-1,m-1, sn, sm, found));
            return debug(ans), dp[n][m][idxn][idxm][found] = ans;
        }

        ans = sum(ans, rec(n-1,m-1, sn, sm, false));
        ans = sum(ans, rec(n-1,m-1, sn, sm, true));
        sn[0] = '1';
        sm[0] = '0';
        ans = sum(ans, rec(n-1,m-1, sn, sm, false));
        ans = sum(ans, rec(n-1,m-1, sn, sm, true));
        return debug(ans), dp[n][m][idxn][idxm][found] = ans;
    }

    string sn = "0"+sufn;
    ans = sum(ans, rec(n-1, m, sn, sufm, found));
    sn[0] = '1';
    ans = sum(ans, rec(n-1, m, sn, sufm, found));
    debug(ans);
    return dp[n][m][idxn][idxm][found] = ans;
}

int main(){
    _;
    prep();
    ll n, m;
    cin >> n >> m;
    cin >> k;
    cin >> w;
    if(k == 1){
        
    }
    // ll ll string string bool 
    memset(dp, -1, sizeof(dp));
    
    ll ans = 0;

    for(auto s1 : lista[k]){
        for(auto s2: lista[k]){
            ans = sum(ans, rec(n,m,s1,s2,true));
        }
    }

    cout << ans << ln;
    if(MAXN < 100) cout << "#########################" << ln;
    return 0;
}