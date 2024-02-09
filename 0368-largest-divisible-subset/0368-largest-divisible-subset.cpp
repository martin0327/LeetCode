class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> dp(n,1);
        int mx = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (a[i] % a[j] == 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        int u = -1;
        for (int i=0; i<n; i++) {
            if (dp[i] == mx) {
                u = i;
                break;
            }
        }
        
        vector<int> ans = {a[u]};
        int p = u;
        while (--u >= 0) {
            if (a[p] % a[u] == 0 && dp[p] == dp[u]+1) {
                ans.push_back(a[u]);
                p = u;
            }
        }
        return ans;
    }
};