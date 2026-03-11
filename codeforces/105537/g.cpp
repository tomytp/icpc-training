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

bool solve_red(vector<p64>& reds, vector<p64>& blues, ll credits) {
    while (blues.size()) {
        bool entered = false;
        while (blues.size() && blues.back().first > reds.back().first) {
            assert(reds.size());
            ll dist = blues.back().first - reds.back().first;
            ll to_kill = min(reds.back().second, blues.back().second);
            if(credits < to_kill*dist) return false;
            
            credits -= dist * to_kill;
            if (to_kill == blues.back().second) blues.pop_back();
            else blues.back().second -= to_kill;
            
            if (to_kill == reds.back().second) reds.pop_back();
            else reds.back().second -= to_kill;
            entered = true;
        }

        if (entered) continue;

        while (blues.size() && reds.back().first > blues.back().first) {
            ll dist = reds.back().first - blues.back().first;
            ll to_kill = min(reds.back().second, blues.back().second);
            credits += dist * to_kill;
            if (to_kill == blues.back().second) blues.pop_back();
            else blues.back().second -= to_kill;
            
            if (to_kill == reds.back().second) reds.pop_back();
            else reds.back().second -= to_kill;
        }

        assert(reds.size());
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    vector<p64> reds, blues;
    ll blue_count = 0, red_count = 0;
    forn(i, 0, n) {
        ll x, m;
        char c;
        cin >> x >> m >> c;
        if (c == 'R') reds.emplace_back(x, m), red_count += m;
        else blues.emplace_back(x, m), blue_count += m;
    }

    if (blue_count == red_count) {
        cout << "Draw 0 0\n";
        return;
    }

    sort(blues.begin(), blues.end());
    sort(reds.begin(), reds.end());

    pair<ll, char> move = {reds.back().first, '+'};
    bool swaped = false;

    while (blue_count && red_count && blues.back().first == reds.back().first + 1 && blues.back().second == 1) {
        blues.pop_back();
        blue_count--;
        red_count--;
        if (reds.back().second == 1) reds.pop_back();
        else reds.back().second--;

        swap(reds, blues);
        swap(red_count, blue_count);
        swaped = !swaped;
    }

    if (blue_count == 0 && red_count != 0) {
        if (!swaped) cout << "First " << move.first << " " << (char)move.second << ln;
        else cout << "Second\n";
        return;
    } else if (red_count == 0 && blue_count != 0) {
        if (!swaped) cout << "Second\n";
        else cout << "First " << move.first << " " << (char)move.second << ln;
        return;
    } else if (red_count + blue_count == 0) {
        cout << "Draw " << move.first << " " << (char)move.second << ln;
        return;
    }

    if (reds.back().first > blues.back().first) {
        if (blue_count >= red_count || !solve_red(reds, blues, 0)) {
            cout << "Draw " << move.first << " " << (char)move.second << ln;
            return;
        } else {
            if (!swaped) cout << "First " << move.first << " " << (char)move.second << ln;
            else cout << "Second" << ln;
            return;
        }
    } else {
        if (red_count >= blue_count || !solve_red(blues, reds, -1)) {
            cout << "Draw " << move.first << " " << (char)move.second << ln;
            return;
        } else {
            if (!swaped) cout << "Second\n";
            else cout << "First " << move.first << " " << (char)move.second << ln;
            return;
        }
    }
}

int main(){
    _;
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}