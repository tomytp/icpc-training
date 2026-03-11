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

const ll sp = 316;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

v64 v;

struct part {
    map<ll, v64> mp;
    ll l, r;
    ll offset = 0;

    part(ll l_, ll r_) : l(l_), r(r_) {
        build();
    }

    ll mx(ll lq, ll rq) {
        if (lq <= l && rq >= r) return mp.rbegin()->first + offset;
        if (rq < l || lq > r) return -INF;
        lq = max(l, lq);
        rq = min(r, rq);
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            for (ll idx : it->second) if (idx >= lq && idx <= rq) return it->first + offset;
        }
        return -INF;
    }

    void reset(ll lq, ll rq, ll val) {
        if (rq < l || lq > r) return;
        if (val == 0) return;
        auto it = prev(mp.end());
        if (it->first + offset != val) return;

        if (lq <= l && rq >= r) {
            v64 neww = move(it->second);
            mp.erase(it);
            auto &old = mp[-offset];
            if (old.empty()) old = move(neww);
            else {
                if (old.size() < neww.size()) old.swap(neww);
                old.insert(old.end(), neww.begin(), neww.end());
            }
            return;
        }
        
        v64 &bot = mp[-offset];
        v64 top;
        for (ll idx : it->second) {
            if (idx >= lq && idx <= rq) {
                bot.push_back(idx);
            } else {
                top.push_back(idx);
            }
        }

        if (top.empty()) mp.erase(it);
        else it->second.swap(top);
        if (bot.empty()) mp.erase(-offset);
    }

    void add(ll lq, ll rq) {
        if (lq <= l && rq >= r) {
            offset++;
            return;
        }
        if (rq < l || lq > r) return;

        map<ll, v64> n_map;

        for(auto &[k, vec] : mp) {
            for (auto x : vec) {
                if (x >= lq && x <= rq) {
                    n_map[k+1].push_back(x);
                } else {
                    n_map[k].push_back(x);
                }
            }
        }
        swap(n_map, mp);
    }
    
    void build() {
        forn(i, l, r+1) {
            mp[v[i]].push_back(i);
        }
    }
    
};

struct jogo {
    vector<part> parts;

    jogo() {
        for (ll i = 0; i < (ll)v.size(); i += sp) parts.push_back(part(i, min(i+sp-1, (ll)v.size()-1)));
    }

    ll mx(ll lq, ll rq) {
        ll ans = -INF;
        for (auto& part: parts) {
            auto temp = part.mx(lq, rq);
            ans = max(ans, temp);
        }
        return ans;
    }

    void reset(ll lq, ll rq) {
        ll val = mx(0, (ll)v.size()-1);
        for (auto& part: parts) {
            part.reset(lq, rq, val);
        }
        val = mx(0, (ll)v.size()-1);
    }

    void add(ll lq, ll rq) {
        for (auto& part: parts) {
            part.add(lq, rq);
        }
    }
};


int main(){
    _;
    ll n, k; cin >> n >> k;
    v.resize(n);
    
    forn(i, 0, n) cin >> v[i];
    
    jogo game;
    forn(lixo, 0, k) {
        char c; cin >> c;
        ll a, b; cin >> a >> b;
        a--;b--;
        if (c == 'Q') {
            cout << game.mx(a, b) << ln;
        } else if (c == 'A') {
            game.add(a, b);
        } else if (c == 'R') {
            game.reset(a, b);
        }
        debug(c);

    }
    return 0;
}