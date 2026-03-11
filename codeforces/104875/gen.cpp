#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define sz(x) ((ll) x.size())
#define ln "\n"

#ifdef DEBUG
#define trace(x) x
#define _
#else
#define trace(x)
#define _ ios::sync_with_stdio(false), cin.tie(0)
#endif

#define debug(x) trace(cout << __LINE__ << ": " #x " = " << x << ln)
#define debugv(v) trace(cout << #v ": "; for (auto xx : v) cout << xx << " "; cout << ln)

const ll INF = 0x3f3f3f3f3f3f3f3fll;


mt19937_64 rng((ll) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

int main() {
    int N = uniform(7, 700);

    if (N == 1) {
        cout << "1" << endl;
        return 0;
    }

    vector<int> p(N);
    p[0] = 1; // logical node 0 is always physical node 1 (The Root)
    
    iota(p.begin() + 1, p.end(), 2);
    
    shuffle(p.begin() + 1, p.end(), rng);

    vector<int> candidates;
    vector<int> degree(N, 0); // Tracks children count for logical indices
    vector<pair<int, int>> edges;

    candidates.push_back(0);

    for (int i = 1; i < N; ++i) {
        uniform_int_distribution<int> dist(0, candidates.size() - 1);
        int rand_pos = dist(rng);
        int parent_idx = candidates[rand_pos];

        // Store edge: Parent -> Child
        // p[parent_idx] is the randomized label of the parent
        // p[i] is the randomized label of the new child
        edges.push_back({p[parent_idx], p[i]});

        // Update parent's degree
        degree[parent_idx]++;

        // If parent has 2 children, remove from candidates
        if (degree[parent_idx] == 2) {
            candidates[rand_pos] = candidates.back();
            candidates.pop_back();
        }

        // The new node 'i' is a leaf (0 children), so it becomes a candidate
        candidates.push_back(i);
    }

    // 5. Output
    cout << N << endl;
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}