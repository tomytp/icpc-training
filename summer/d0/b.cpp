/**
 * Competitive Programming - C++ Solution
 * Problem: Optimizing Fishermen's Morale (Graph Cycles + DP)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll INF = 1e18; // Large enough to handle sums of negative scores

struct Edge {
    int to;
    int val_idx; // The number (0..n-1) representing this edge
};

int n;
vector<int> p, q;
vector<ll> a, b, c;
vector<vector<Edge>> adj;
vector<bool> visited;

ll get_score(int val_idx, int count) {
    if (count == 0) return a[val_idx];
    if (count == 1) return b[val_idx];
    return c[val_idx];
}

void solve() {
    cin >> n;
    
    p.resize(n);
    q.resize(n);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    
    vector<pair<int, int>> val_positions(n); 

    for (int i = 0; i < n; i++) { 
        cin >> p[i]; 
        p[i]--; // 0-based value
        val_positions[p[i]].first = i; 
    }
    for (int i = 0; i < n; i++) { 
        cin >> q[i]; 
        q[i]--; // 0-based value
        val_positions[q[i]].second = i; 
    }
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    adj.assign(n, vector<Edge>());
    for (int val = 0; val < n; val++) {
        int u = val_positions[val].first;
        int v = val_positions[val].second;
        
        adj[u].push_back({v, val});
        if (u != v) {
            adj[v].push_back({u, val});
        }
    }

    visited.assign(n, false);
    ll total_max_morale = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        vector<int> nodes;
        vector<int> edge_values; 
        
        int curr = i;
        int prev_val = -1; // Value of the edge used to reach 'curr'

        while (true) {
            visited[curr] = true;
            nodes.push_back(curr);
            
            int next_node = -1;
            int next_val = -1;
            
            for (auto& e : adj[curr]) {
                if (e.val_idx == prev_val) continue;
                
                next_node = e.to;
                next_val = e.val_idx;
                break; // Because degree is exactly 2, picking the first valid non-prev is correct
            }
            
            edge_values.push_back(next_val);
            
            if (next_node == i) {
                break;
            }
            
            curr = next_node;
            prev_val = next_val;
        }

        int k = nodes.size();
        ll current_cycle_max = -INF;

        for (int start_choice = 0; start_choice < 2; start_choice++) {
            // dp[choice] stores the max score considering edges processed so far,
            // ending with the current node making 'choice'.
            // choice 0 = Left, choice 1 = Right.
            
            // Initialize for node 0
            vector<ll> dp_curr(2, -INF);
            dp_curr[start_choice] = 0; 
            
            // Process edges 0 to k-2 (transitions from node 0->1, 1->2 ... k-2->k-1)
            for (int j = 1; j < k; j++) {
                vector<ll> dp_next(2, -INF);
                int edge_val = edge_values[j-1]; // Edge connecting (j-1) and j
                
                for (int prev_choice = 0; prev_choice < 2; prev_choice++) { // Choice of node j-1
                    if (dp_curr[prev_choice] == -INF) continue;
                    
                    for (int curr_choice = 0; curr_choice < 2; curr_choice++) { // Choice of node j
                        
                        // Calculate score for this edge
                        // Edge is selected by (j-1) if it picked Right (1)
                        // Edge is selected by j     if it picked Left (0)
                        
                        int count = (prev_choice == 1) + (curr_choice == 0);
                        dp_next[curr_choice] = max(dp_next[curr_choice], dp_curr[prev_choice] + get_score(edge_val, count));
                    }
                }
                dp_curr = dp_next;
            }
            
            // Close the loop: Edge connecting k-1 back to 0
            int last_edge_val = edge_values[k-1];
            
            for (int end_choice = 0; end_choice < 2; end_choice++) { // Choice of node k-1
                if (dp_curr[end_choice] == -INF) continue;
                
                // Edge is selected by (k-1) if it picked Right (1)
                // Edge is selected by 0     if it picked Left (0)
                // Note: Node 0's choice is fixed to 'start_choice'
                
                int count = (end_choice == 1) + (start_choice == 0);
                ll final_val = dp_curr[end_choice] + get_score(last_edge_val, count);
                
                current_cycle_max = max(current_cycle_max, final_val);
            }
        }
        
        total_max_morale += current_cycle_max;
    }

    cout << total_max_morale << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}