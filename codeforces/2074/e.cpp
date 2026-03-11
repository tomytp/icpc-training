#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64; 
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n"

const ll INF = 0x3f3f3f3f3f3f3f3fll;

void interact(char c, v64 points) {
    cout << c << " " << points[0] << " " << points[1] << " " << points[2] << ln;
    cout.flush(); 
}

mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

void solve(){
    ll n; cin >> n;
    v64 points = {1, uniform(2, n-1), n};
    interact('?', points);
    ll ans; cin >> ans;
    while (ans != 0) {
        points[uniform(0, 2)] = ans;
        interact('?', points);
        cin >> ans;
    }
    interact('!', points);
}

int main(){
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}