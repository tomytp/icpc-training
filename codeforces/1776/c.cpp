#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln endl

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll n, m, bob; 
v64 x, vec;

void play_bob(){
    forn(i,0,n){
        ll c,l,r;
        cin >> c >> l;
        l--;
        r = l+c-1;
        ll resp = l+1;

        forn(j,l,r+1){
            if((j+1) % x[bob] == 0){
                resp = j+1;
            } 
        }
        cout << resp << ln;
    }
}

void play_not_bob(){
    forn(i,0,n){
        ll k = x[i];
        ll sum = 0;

        forn(j,0,k) sum += vec[j];
        bool printed = false;

        forn(l,0, m-k+1){
            if(sum == 0){
                cout << k << " " << l+1 << ln;
                printed = true;
                break;
            }
            sum += vec[l+k];
            sum -= vec[l];
        }
        assert(printed);
        ll resp; cin >> resp;
        vec[resp-1] = 1;   
    }
}   

int main(){
    _;
    cin >> n >> m;
    x.resize(n);
    vec.resize(m,0);
    forn(i, 0, n) cin >> x[i];
    sort(x.rbegin(), x.rend());
    bob = -1;

    forn(i, 0, n) {
        if (i + 1 > m/x[i]) {
            bob = i;
            break;
        }
    }
    if (bob != -1) {
        cout << "Bernardo" << endl;
    }  else {
        cout << "Alessia" << endl;
    }

    if (bob != -1) {
        play_bob();
    } else {
        play_not_bob();
    }

    return 0;
}
