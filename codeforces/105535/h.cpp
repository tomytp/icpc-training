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

string caps(string s) {
    string s2;
    forn(i, 0, s.size()) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s2.push_back(s[i] - 'a' + 'A');
        } else {
            s2.push_back(s[i]);
        }
    }
    return s2;
}

int main(){
    _;
    string s;
    getline(cin, s);
    cout << "What is the name of your team?\n";
    cout << "Our name is " << s << ".\n";
    cout << "My apologies, I did not understand. What is your team name?" << ln;
    cout << "We are team " << s << ".\n";
    cout << "I am really sorry. Could you please repeat it once again?\n";
    cout << "WE ARE TEAM " << caps(s) << "!!!" << ln;
    cout << "Oh, now I see. Here are your badges. Good luck!\n";
    return 0;
}