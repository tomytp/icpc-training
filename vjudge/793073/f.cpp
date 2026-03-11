    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll, ll> p64;
    typedef vector<ll> v64;

    #define forn(i, s, e) for (ll i = (s); i < (e); i++)
    #define sz(u) ((ll) u.size())
    #define ln "\n"

    #ifdef DEBUG
    #define trace(u) u
    #define _
    #else
    #define trace(u)
    #define _ ios::sync_with_stdio(0); cin.tie(0)
    #endif

    #define debug(u) trace(cout << #u " = " << u << ln)
    #define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

    const ll INF = 0x3f3f3f3f3f3f3f3fll;
    const ll MAX = 1'000'005;
    const ll MOD = 1'000'000'009;

    template<ll p> struct mod_int {
        ll expo(ll b, ll e) {
            ll ret = 1;
            while (e) {
                if(e%2) ret = ret *b%p;
                e/=2, b= b*b%p;
            }
            return ret;
        }
        ll inv(ll b) {return expo(b, p-2);}

        using m = mod_int;
        ll v;
        mod_int() : v(0) {}
        mod_int(ll v_) {
            if(v_ >= p || v_ <= -p) v_ %= p;
            if(v_ < 0) v_ += p;
            v = v_;
        }
        m& operator += (const m& a) {
            v += a.v;
            if(v >= p) v -= p;
            return *this;
        }
        m& operator -= (const m& a) {
            v -= a.v;
            if(v<0) v += p;
            return *this;
        }
        m& operator *=(const m& a) {
            v = v*a.v%p;
            return *this;
        }
        m& operator /=(const m& a) {
            v = v* inv(a.v) % p;
            return *this;
        }
        m operator -() const { return m(-v);}
        m&operator ^=(ll e) {
            if(e < 0) {
                v = inv(v);
                e = -e;
            }
            v = expo(v, e);
            return *this;
        }
        bool operator == (const m& a) {return v == a.v;}
        bool operator != (const m& a) {return v != a.v;}

        friend istream& operator >>(istream& in, m& a) {
            ll val; in >> val;
            a = m(val);
            return in;
        }
        friend ostream& operator <<(ostream& out, m& a) {
            return out << a.v;
        }
        friend m operator +(m a, m b) { return a += b; }
        friend m operator -(m a, m b) { return a -= b; }
        friend m operator *(m a, m b) { return a *= b; }
        friend m operator /(m a, m b) { return a /= b; }
        friend m operator ^(m a, ll e) { return a ^= e; }
    };
    typedef mod_int<MOD> mint;

    mint base = 31;
    mint invb = base^(-1);

    vector<vector<string>> table;

    vector<mint> potb(MAX); 
    vector<mint> potinvb(MAX);

    void prep(){
        potb[0] = 1;
        potinvb[0] = 1;

        forn(i,1,MAX){
            potb[i] = base*potb[i-1];
            potinvb[i] = invb*potinvb[i-1];
        }
    }

    vector<mint> calc_hash(string& s){
        ll n = sz(s);
        vector<mint> vec(n);
        forn(i,0,n){
            vec[i] = (s[i]-'a')*potb[i] + (i == 0 ? 0 : vec[i-1]);
        }

        // debug(s);
        // debugv(vec);
        return vec;
    }

    int main() {
        _;
        prep();
        ll n; cin >> n;
        table.resize(n, vector<string>(n));
        vector<vector<vector<mint>>> ht(n, vector<vector<mint>>(n));
        vector<pair<ll, mint>> times(n);
        vector<pair<ll, mint>> best_times(n);

        forn(i, 0, n)
        forn(j, 0, n){
            cin >> table[i][j];
            if(i != j) ht[i][j] = calc_hash(table[i][j]);
        }

        auto get_hash = [&](ll l, ll r, vector<mint>& vec){
            mint aux = vec[r] - (l == 0 ? 0 : vec[l-1]);
            aux *= potinvb[l];
            return aux;

        };

        ll mxsz = sz(table[0][1]);
        ll cnt = 0;

        forn(tam, 0, mxsz-1){
            debug(tam);
            times[0] = {tam+1, ht[0][1][tam]};
            
            bool f = false;

            forn(i,1,n){
                if(times[0].second != ht[0][i][tam]){
                    f = true;
                    break;
                }
                times[i] = {sz(ht[0][i])-(tam+1), get_hash(tam+1,sz(ht[0][i])-1, ht[0][i])};
            }

            // debug(f);
        
            if(f) continue;

            forn(i,1,n){
                forn(j,0,n){
                    if(i == j) continue;
                    if(times[i].first + times[j].first != sz(ht[i][j])){
                        f = true;
                        break;
                    }
                    mint hi = get_hash(0, times[i].first-1, ht[i][j]);
                    mint hj = get_hash(times[i].first, sz(ht[i][j])-1, ht[i][j]);

                    // debug(i);
                    // debug(hi);
                    // debug(j);
                    // debug(hj);

                    if(hi != times[i].second || hj != times[j].second){
                        f = true;
                        break;
                    }
                }
                if(f) break;
            }
            if(f) continue;
            cnt++;
            if(cnt > 1) break;
            best_times = times;
        }

        if(cnt > 1){
            cout << "MANY" << ln;
            return 0;
        }

        if(cnt == 0){
            cout << "NONE" << ln;
            return 0;
        }

        trace(
            forn(i, 0, n)cout << best_times[i].first << " " << best_times[i].second << ln;
        );

        cout << "UNIQUE" << ln; 
        cout << table[0][1].substr(0, best_times[0].first) << ln;
        forn(i, 1, n) cout << table[i][0].substr(0, best_times[i].first) << ln;
        return 0;
    }
