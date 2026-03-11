#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const ll MAX = 100'000;
const ll MOD = 998244353;

string alfa = "IVXLCDM";

struct aho {
    map<char, ll> to[MAX];
    ll link[MAX], idx, term[MAX];

    void insert(string& s) {
        ll at = 0;
        for (char c : s) {
            auto it = to[at].find(c);
            // debug(at);
            if (it == to[at].end()) at = to[at][c] = ++idx;
            else at = it->second;
        }
        term[at]++;
    }

    void build() {
        queue<ll> q;
        q.push(0);
        link[0] = -1;
        while (q.size()) {
            ll i = q.front(); q.pop();
            for (auto [c, j] : to[i]) {
                ll l = link[i];
                while (l != -1 and !to[l].count(c)) l = link[l];
                link[j] = l == -1 ? 0 : to[l][c];
                q.push(j);
            }
        }

        forn(i, 0, idx){
            for(auto c : alfa){
                ll aux = i;
                while (aux != -1 and !to[aux].count(c)) aux = link[aux];
                if(aux == -1) to[i][c] = 0;
                else to[i][c] = to[aux][c];
            }
        }
    }
};

template<ll p> struct mod_int {
    ll expo(ll b, ll e) {
        ll ret = 1;
        while (e) {
            if (e % 2) ret = ret * b % p;
            e /= 2, b = b * b % p;
        }
        return ret;
    }
    ll inv(ll b) { return expo(b, p-2); }

    using m = mod_int;
    ll v;
    mod_int() : v(0) {}
    mod_int(ll v_) {
        if (v_ >= p or v_ <= -p) v_ %= p;
        if (v_ < 0) v_ += p;
        v = v_;
    }
    m& operator +=(const m& a) {
        v += a.v;
        if (v >= p) v -= p;
        return *this;
    }
    m& operator -=(const m& a) {
        v -= a.v;
        if (v < 0) v += p;
        return *this;
    }
    m& operator *=(const m& a) {
        v = v * a.v % p;
        return *this;
    }
    m& operator /=(const m& a) {
        v = v * inv(a.v) % p;
        return *this;
    }
    m operator -() const { return m(-v); }
    m& operator ^=(ll e) {
        if (e < 0) {
            v = inv(v);
            e = -e;
        }
        v = expo(v, e);
        // possible optimization:
        // careful with 0^0
        // v = expo(v, e%(p-1)); 
        return *this;
    }
    bool operator ==(const m& a) { return v == a.v; }
    bool operator !=(const m& a) { return v != a.v; }

    friend istream& operator >>(istream& in, m& a) {
        ll val; in >> val;
        a = m(val);
        return in;
    }
    friend ostream& operator <<(ostream& out, m a) {
        return out << a.v;
    }
    friend m operator +(m a, m b) { return a += b; }
    friend m operator -(m a, m b) { return a -= b; }
    friend m operator *(m a, m b) { return a *= b; }
    friend m operator /(m a, m b) { return a /= b; }
    friend m operator ^(m a, ll e) { return a ^= e; }
};
typedef mod_int<MOD> mint;

vector<vector<string>> dict(16);

void prepare(){
    vector<string> th ={"", "M", "MM", "MMM"};
    vector<string> hu ={"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> te ={"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> un ={"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    forn(uni, 0, 10)
    forn(ten, 0, 10)
    forn(hun, 0, 10)
    forn(tho, 0, 4){
        string roman = th[tho];
        roman += hu[hun];
        roman += te[ten];
        roman += un[uni];
        debug(roman);
        dict[sz(roman)].push_back(roman);
    }
}

mint solve(ll k, ll n){
    // for(auto s : dict[k]){
    //     cout << "===========\n";
    //     debug(s);
    //     cout << "===========\n";
    // }
    debug(k);

    aho cora;
    for(auto s : dict[k]) cora.insert(s);
    cora.build();
    ll estados = cora.idx;

    vector<vector<mint>> dp(n+1, vector<mint>(cora.idx, 0));
    dp[0][0] = 1;
    forn(i, 0, n){
        forn(e, 0, estados){
            for(auto c : alfa){
                if(cora.term[cora.to[e][c]] != 0) continue;
                dp[i+1][cora.to[e][c]] += dp[i][e];
            }
        }
    }

    mint total = 0;
    forn(e, 0, estados){
        total += dp[n][e];
    }

    return total;
}

int main(){
    _; prepare();
    ll n; cin >> n; 
    mint sum = 0;

    forn(k, 1, 16){
        sum += solve(k, n);
    }

    mint ans = 15 - sum/(7^n);

    cout << ans << ln;

    return 0;
}