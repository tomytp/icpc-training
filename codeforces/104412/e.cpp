#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll,ll> p64;

#define forn(i, s, e) for(ll i = (s); i < (e); i++)
#define sz(x) ((ll) (x).size())
#define ln "\n"

#ifdef DEBUG
    #define trace(x) x
    #define _ (void)0
#else
    #define trace(x) (void)0
    #define _ ios_base::sync_with_stdio(false), cin.tie(NULL)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll max_day = 3'653'000;


int get_id(int d, int m, int y) {
    if (m < 3) y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * (m - 3) + 2) / 5 + d - 307;
}

ll weekday(ll id) {
    // 0 SEGUNDA
    // 1 TERCA...
    return id%7;
}

tuple<int, int, int> date(int id) {
    int x = id + 1789995, n = 4 * x / 146097, i, j, d, m, y;
    x -= (146097 * n + 3) / 4;
    i = (4000 * (x + 1)) / 1461001;
    x -= 1461 * i / 4 - 31;
    j = 80 * x / 2447, d = x - 2447 * j / 80;
    x = j / 11;
    m = j + 2 - 12 * x, y = 100 * (n - 49) + i + x;
    return {d, m, y};
}

enum job_type {
    weekly, monthly, biweekly
};

struct job {
    ll start, end, amount;
    job_type type;
};

ll convert(string s, bool st) {
    if (s[0] == 'N') {
        if (st) return 5;
        else return max_day- 5;
    }
    ll day = (s[0] - '0') * 10 + (s[1] - '0');
    ll month = (s[3] - '0') * 10 + (s[4] - '0');
    ll year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    return get_id(day, month, year); 
}


int main() {
    _;
    ll n, q; cin >> n >> q;

    
    vector<job> jobs(n);
    vector<v64> starts(max_day), ends(max_day);
    v64 prefix(max_day);
    forn(i, 0, n) {
        cin >> jobs[i].amount;
        string dt; cin >> dt;
        jobs[i].start = convert(dt, true);
        cin >> dt;
        jobs[i].end = convert(dt, false);
        cin >> dt;
        if (dt[0] == 'b') jobs[i].type = biweekly;
        if (dt[0] == 'w') jobs[i].type = weekly;
        if (dt[0] == 'm') jobs[i].type = monthly;
        starts[jobs[i].start].push_back(i);
        ends[jobs[i].end].push_back(i);
    }


    ll b = 0, w = 0, m = 0;
    forn(d, 1, max_day) {
        for (auto x : starts[d]) {
            if (jobs[x].type == monthly) m += jobs[x].amount;
            if (jobs[x].type == weekly) w += jobs[x].amount;
            if (jobs[x].type == biweekly) b += jobs[x].amount;
        }


        prefix[d] = prefix[d-1];
        auto dt = date(d);
        auto dt2 = date(d+1);

        if (weekday(d) == 4) prefix[d] += w;
        if (get<0>(dt) == 15) prefix[d] += b;
        if (get<1>(dt) != get<1>(dt2)) {
            prefix[d] += b + m;
        }

        for (auto x : ends[d]) {
            if (jobs[x].type == monthly) m -= jobs[x].amount;
            if (jobs[x].type == weekly) w -= jobs[x].amount;
            if (jobs[x].type == biweekly) b -= jobs[x].amount;
        }
    }

    forn(i,0, q) {
        string a, bb; cin >> a >> bb;
        ll ida = convert(a, false), idb = convert(bb, false);
        cout << prefix[idb] - prefix[ida-1] << ln;
    }

    return 0;
}