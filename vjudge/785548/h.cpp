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
#define debugm(v) trace(cout << #v ": "; for (auto xx : v) cout << xx.first << ":" << xx.second << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


int main() {
    _;
    ll n, m; cin >> n >> m;

    vector<p64> islands(n);
    vector<p64> brid(m);

    forn(i,0,n) cin >> islands[i].first >> islands[i].second;
    forn(i,0,m){
        cin >> brid[i].first;
        brid[i].second = i;
    }

    if(m < n-1){
        cout << "No" << ln;
        return 0;
    }

    vector<pair<p64, ll>> bounds(n-1);

    forn(i,0,n-1){
        ll low = islands[i+1].first - islands[i].second;        
        ll upp = islands[i+1].second - islands[i].first;
        bounds[i] = {{low,upp}, i};
    }

    sort(bounds.begin(), bounds.end());
    sort(brid.begin(), brid.end());

    v64 resp(n-1, -1);

    ll p1 = 0;
    
    set<p64> s; // upp, idx
    forn(p2, 0, m){
        debugm(s);
        while(p1 < n-1 && bounds[p1].first.first <= brid[p2].first){
            s.insert({bounds[p1].first.second, bounds[p1].second});
            p1++;
        }

        if(sz(s) == 0) continue;

        p64 tenta = *s.begin();

        if(tenta.first < brid[p2].first){
            cout << "No" << ln;
            return 0;
        }

        resp[tenta.second] = brid[p2].second;
        s.erase(tenta);
    }


    bool ruim = false;
    forn(i,0,n-1) if(resp[i] == -1) ruim = true;
    
    if(ruim){
        cout << "No" << ln;
        return 0;
    } 

    cout << "Yes" << ln;
    forn(i, 0, n-1) cout << resp[i]+1 << " \n"[i==n-2];
    return 0;
}
 