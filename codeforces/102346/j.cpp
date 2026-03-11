#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define ln "\n";

#if defined(DEBUG)
    #define _ (void)0
    #define debug(x) cout << __LINE__ << ": " << #x << " = " << x << ln
#else
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
    #define debug(x) (void)0
#endif

const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll val(char c) {
    if (c == 'A') return 0;
    if (c == '2') return 1;
    if (c == '3') return 2;
    if (c == '4') return 3;
    if (c == '5') return 4;
    if (c == '6') return 5;
    if (c == '7') return 6;
    if (c == '8') return 7;
    if (c == '9') return 8;
    if (c == 'D') return 9;
    if (c == 'Q') return 10;
    if (c == 'J') return 11;
    if (c == 'K') return 12;
    return -1;
}

bool is_winner(ll p,v64& v, ll joker) {
    if (joker == p) return false;
    ll sum = 0, count = 0;
    for(auto x : v) {
        if (x) sum += x, count++;
    }
    return (sum == 4 && count == 1);
}

int main() {
    _;
    ll n, k; cin >> n >> k;
    k--;

    vector<v64> hands(n, v64(13));
    
    forn(i, 0, n) {
        string s; cin >> s;
        for (char c : s) hands[i][val(c)]++;
    }
    ll joker = k;
    ll joker_move = 0;
    ll moves = 0;
    ll player = k;

    forn(i, 0, n) {
        if (is_winner(i, hands[i], joker)) {
            cout << i + 1 << ln;
            return 0;
        }        
    }

    while (true) {
        if (joker == player && joker_move < moves) {
            joker = (joker + 1) % n;
            if (is_winner(player, hands[player], joker)) {
                cout << player + 1 << ln;
                return 0;
            }    
            joker_move = ++moves;
            player = (player + 1) % n;
            continue;
        }

        ll best = -1, count = INF;
        forn(i, 0, 13) {
            if (hands[player][i] < count && hands[player][i] > 0) {
                best = i;
                count = hands[player][i];
            }
        }
        moves++;
        hands[player][best]--;
        if (is_winner(player, hands[player], joker)) {
            cout << player + 1 << ln;
            return 0;
        }        
        player = (player + 1) % n;
        hands[player][best]++;    
    }

    return 0;
}