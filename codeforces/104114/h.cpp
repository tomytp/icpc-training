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

int main(){
    _;
    ll n; cin >> n;
    v64 v(n);
    forn(i, 0, n) cin >> v[i];
    
    stack<ll> a, b, c;
    forn(i, 0, n) a.push(v[i]);
    vector<p64> ans;

    while (true) {
        ans.emplace_back(1, 3);
        c.push(a.top());
        a.pop();
        
        while (a.size() && c.top() > a.top()) {
            ans.emplace_back(1, 3);
            c.push(a.top());
            a.pop();
        }
        
        if (c.size() == n) {
            break;
        }

        ans.emplace_back(1, 2);
        b.push(a.top());
        a.pop();

        while (c.size()) {
            ll atop = -1;
            if (a.size()) atop = a.top();
            ll ctop = INF;
            if (c.size()) ctop = c.top();
            if (b.size() && b.top() >atop && b.top() < ctop) {
                ans.emplace_back(2, 1);
                a.push(b.top());
                b.pop();
                continue;
            }
            ans.emplace_back(3, 1);
            a.push(c.top());
            c.pop();
        }
        ll atop = -1;
        if (a.size()) atop = a.top();
        ll ctop = INF;
        if (c.size()) ctop = c.top();
        if (b.size() && b.top() >atop && b.top() < ctop) {
            ans.emplace_back(2, 1);
            a.push(b.top());
            b.pop();
            continue;
        }
    }    

    cout << ans.size() << ln;
    for (auto [x, y] : ans) {
        cout << x << " " << y << ln;
    }
    return 0;
}