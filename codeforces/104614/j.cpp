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

int main(){
    _;
    ll n = 52;
    vector<string> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }

    vector<string> hand;

    ll swaped = false;
    do {
        swaped = false;
        for (ll i = hand.size()-4; i >= 0; i--) {
            // i | i + 3
            if (hand[i][0] == hand[i+3][0]) {
                debug(hand[i]);
                debug(hand[i + 3]);
                hand.erase(hand.begin() + i);
                hand.erase(hand.begin() + i);
                hand.erase(hand.begin() + i);
                hand.erase(hand.begin() + i);
                swaped = true;
                break;
            } 
        }
        if (!swaped) {
            for (ll i = hand.size()-4; i >= 0; i--) {
                if (hand[i][1] == hand[i+3][1]) {
                    debug(hand[i]);
                    debug(hand[i + 3]);
                    hand.erase(hand.begin() + i + 3);
                    hand.erase(hand.begin() + i);
                    swaped = true;
                    break;
                }
            }
        }
        if (!swaped) {
            if (v.size() == 0) break;
            hand.push_back(v[0]);
            v.erase(v.begin());
            swaped = true;
        }

    } while (swaped == true);
    
    cout << hand.size() << " ";
    forn(i, 0, hand.size()) cout << hand[i] << " \n"[i==hand.size() - 1];


    return 0;
}