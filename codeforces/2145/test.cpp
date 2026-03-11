#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll)(x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debugv(v) trace({ cout << #v": "; for (auto _x : v) cout << _x << " "; cout << ln; })
#define debug(x)  trace(cout << __LINE__ << ": " #x " = " << (x) << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;

// ===== inversion value =====
static inline ll inversion_value(const v64 &p) {
    ll n = sz(p);
    ll total = n * (n - 1) / 2;
    ll inc_sum = 0, run = 1;
    forn(i, 1, n) {
        if (p[i-1] < p[i]) run++;
        else { inc_sum += run * (run - 1) / 2; run = 1; }
    }
    inc_sum += run * (run - 1) / 2;
    return total - inc_sum;
}

// ===== k atingível via DP de composições de runs =====
static vector<char> reachable_k_for_n(int n){
    int Tn = n*(n-1)/2;
    vector<vector<char>> dp(n+1, vector<char>(Tn+1, 0));
    dp[0][0] = 1;
    auto Tri = [](int r){ return r*(r-1)/2; };
    for(int r=1;r<=n;r++){
        int Tr = Tri(r);
        for(int len=n-r; len>=0; --len){
            for(int s=0; s+Tr<=Tn; s++){
                if(dp[len][s]) dp[len+r][s+Tr] = 1;
            }
        }
    }
    vector<char> ok(Tn+1,0);
    for(int s=0;s<=Tn;s++) if(dp[n][s]) ok[Tn - s] = 1;
    return ok;
}

// ===== constrói permutação para (n,k) atingível =====
// acha uma composição n = r1+...+rm com sum T_{ri} = Tn-k e monta blocos crescentes
static bool build_perm(int n, long long k, vector<int>& out){
    int Tn = n*(n-1)/2;
    if(k<0 || k> Tn) return false;
    vector<char> ok = reachable_k_for_n(n);
    if(!ok[k]) return false;
    int target = Tn - (int)k;

    vector<vector<char>> dp(n+1, vector<char>(target+1, 0));
    dp[0][0] = 1;
    auto Tri=[&](int r){return r*(r-1)/2;};
    for(int len=0; len<=n; ++len){
        for(int s=0; s<=target; ++s){
            if(!dp[len][s]) continue;
            for(int r=1; len+r<=n; ++r){
                int tr=Tri(r);
                if(s+tr<=target) dp[len+r][s+tr]=1;
            }
        }
    }
    vector<int> runs;
    int len=n, s=target;
    while(len>0){
        bool took=false;
        for(int r=1; r<=len; ++r){
            int tr=Tri(r);
            if(s-tr>=0 && dp[len-r][s-tr]){
                runs.push_back(r);
                len-=r; s-=tr; took=true; break;
            }
        }
        if(!took) return false;
    }
    out.clear(); out.reserve(n);
    int cur=n;
    for(int r: runs){
        int start=cur-r+1;
        for(int v=start; v<=cur; ++v) out.push_back(v);
        cur-=r;
    }
    return (int)out.size()==n;
}

// ===== GERADOR: preenche com aleatório e completa faltantes com build_perm =====
int main(){
    _;
    // config do gerador
    const int NMIN = 2, NMAX = 30;
    const long long MS_PER_N = 800;   // tempo por n (ms)
    const long long ITER_PER_N = -1;  // se >0, usa nº de iterações
    const long long MAX_WITHOUT = 2'000'000;
    const int RESEED_EVERY = 200'000;

    mt19937_64 rng((uint64_t)chrono::high_resolution_clock::now().time_since_epoch().count());

    struct Block { int n; ll Kmax; vector<char> ok; vector<array<int,31>> P; };
    vector<Block> blocks; blocks.reserve(NMAX - NMIN + 1);

    for(int n=NMIN; n<=NMAX; n++){
        ll Kmax = 1LL*n*(n-1)/2;
        vector<char> ok = reachable_k_for_n(n);

        vector<char> got(Kmax+1, 0);
        vector<v64> perm(Kmax+1);

        auto try_perm = [&](const v64& p)->bool{
            ll k = inversion_value(p);
            if(k<0 || k> Kmax || !ok[k]) return false;
            if(!got[k]){ perm[k]=p; got[k]=1; return true; }
            return false;
        };

        // seeds
        v64 base(n); iota(base.begin(), base.end(), 1);
        v64 rev = base; reverse(rev.begin(), rev.end());
        try_perm(base); try_perm(rev);

        // random search
        v64 cur = base; shuffle(cur.begin(), cur.end(), rng);
        uniform_int_distribution<int> dist(0, n-1);
        auto t0 = chrono::steady_clock::now();
        long long it=0, without=0, total_swaps=0;

        auto time_ok = [&](){
            if(ITER_PER_N>0) return it<ITER_PER_N;
            auto now = chrono::steady_clock::now();
            return chrono::duration_cast<chrono::milliseconds>(now - t0).count() < MS_PER_N;
        };

        while(time_ok()){
            int i=dist(rng), j=dist(rng);
            if(i==j) continue;
            if(i>j) swap(i,j);
            swap(cur[i],cur[j]);
            bool progress = try_perm(cur);
            total_swaps++; it++;
            if(progress) without=0;
            else { swap(cur[i],cur[j]); without++; }
            if(without>=MAX_WITHOUT){
                cur = base; shuffle(cur.begin(),cur.end(),rng); without=0;
            }
            if(total_swaps % RESEED_EVERY == 0){
                rng.seed(rng() ^ chrono::high_resolution_clock::now().time_since_epoch().count());
            }
        }

        // completa TODOS os k atingíveis com fallback determinístico
        for(int k=0; k<=Kmax; k++){
            if(!ok[k]) continue;
            if(!got[k]){
                vector<int> out;
                bool okb = build_perm(n, k, out);
                if(okb){
                    perm[k].assign(out.begin(), out.end());
                    got[k]=1;
                }else{
                    // não deve ocorrer; ok[k]==1 garante construção
                }
            }
        }

        // compacta para impressão (arrays fixos até 31 colunas)
        Block B; B.n=n; B.Kmax=Kmax; B.ok=ok; B.P.assign(Kmax+1, array<int,31>{});
        for(int k=0; k<=Kmax; k++){
            array<int,31> row{}; // zera
            if(ok[k]){
                for(int i=0;i<n;i++) row[i] = (int)perm[k][i];
            }else{
                for(int i=0;i<n;i++) row[i] = i+1; // dummy; será bloqueado por OK
            }
            B.P[k]=row;
        }
        blocks.push_back(move(B));
        cerr << "[n="<<n<<"] pronto" << ln;
    }

    // ===== imprime SUBMISSION COMPLETO =====
    cout << "#include <bits/stdc++.h>\n";
    cout << "using namespace std;\n";
    cout << "typedef long long ll; typedef vector<int> vi;\n";
    cout << "#define ln \"\\n\"\n";
    cout << "#define _ ios_base::sync_with_stdio(false), cin.tie(NULL)\n\n";

    // imprime tabelas
    cout << "namespace data {\n";
    for(auto &B: blocks){
        cout << "  // n = " << B.n << "\n";
        cout << "  static const int N_"<<B.n<<" = "<<B.n<<";\n";
        cout << "  static const long long KMAX_"<<B.n<<" = "<<B.Kmax<<";\n";
        cout << "  static const unsigned char OK_"<<B.n<<"["<<(B.Kmax+1)<<"] = {";
        for(int k=0;k<=B.Kmax;k++) cout << (B.ok[k]? '1':'0') << (k==B.Kmax? "":",");
        cout << "};\n";
        cout << "  static const int P_"<<B.n<<"["<<(B.Kmax+1)<<"]["<<B.n<<"] = {\n";
        for(int k=0;k<=B.Kmax;k++){
            cout << "    {";
            for(int i=0;i<B.n;i++){
                cout << B.P[k][i] << (i+1<B.n? ",":"");
            }
            cout << "}" << (k==B.Kmax? "":",") << "\n";
        }
        cout << "  };\n\n";
    }
    cout << "} // namespace data\n\n";

    // getter
    cout << "static bool get_perm(int n, long long k, vector<int>& out){\n";
    cout << "  switch(n){\n";
    for(auto &B: blocks){
        cout << "    case " << B.n << ": {\n";
        cout << "      if(k<0 || k>data::KMAX_"<<B.n<<") return false;\n";
        cout << "      if(!data::OK_"<<B.n<<"[k]) return false;\n";
        cout << "      out.assign(&data::P_"<<B.n<<"[k][0], &data::P_"<<B.n<<"[k][0]+"<<B.n<<");\n";
        cout << "      return true;\n";
        cout << "    }\n";
    }
    cout << "    default: return false;\n";
    cout << "  }\n";
    cout << "}\n\n";

    // solve + main
    cout << "static void solve(){ _; int T; if(!(cin>>T)) return; while(T--){ long long n,k; cin>>n>>k; vector<int> p; if(!get_perm((int)n,k,p)){ cout<<-1<<ln; } else { for(int i=0;i<(int)p.size();i++){ if(i) cout<<' '; cout<<p[i]; } cout<<ln; } } }\n";
    cout << "int main(){ solve(); return 0; }\n";

    return 0;
}
