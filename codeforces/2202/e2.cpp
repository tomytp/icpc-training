#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[300002];
        scanf("%s", s + 1);
        
        vector<int> ps(n + 1);
        for (int i = 1; i <= n; i++)
            ps[i] = ps[i-1] + (s[i] == '(' ? 1 : -1);
        
        long long ans = n % MOD;
        
        // Case 2: length >= 2, last element is '('
        // Any subsequence ending at '(' is valid (all prefix sum changes >= 0)
        long long pow2 = 1; // 2^{j-1} for j starting at 1
        for (int j = 1; j <= n; j++) {
            if (s[j] == '(') {
                ans = (ans + pow2 - 1 + MOD) % MOD;
            }
            pow2 = pow2 * 2 % MOD;
        }
        
        // Case 3: length >= 2, last element is ')'
        // g[j] = number of valid chains ending at j
        // Constraint: from '(' at pos i to next pos j, need min prefix_sum in [i,j-1] >= 2
        // Equivalent: i > last_low(j) where last_low(j) = max{p<=j-1 : ps[p]<2}
        vector<long long> psum_open(n + 1, 0); // prefix sum of g[i] over '(' positions
        long long sum_close = 0;
        int ll = 0; // ps[0]=0 < 2
        
        for (int j = 1; j <= n; j++) {
            int llj = ll;
            
            long long gj = (1 + sum_close + (psum_open[j-1] - psum_open[llj] + MOD) % MOD) % MOD;
            
            if (s[j] == '(') {
                psum_open[j] = (psum_open[j-1] + gj) % MOD;
            } else {
                psum_open[j] = psum_open[j-1];
                ans = (ans + gj - 1 + MOD) % MOD;
                sum_close = (sum_close + gj) % MOD;
            }
            
            if (ps[j] < 2) ll = j;
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}