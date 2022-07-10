class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        a.push_back(0);
        vector<int> dp(n+1);
        dp[0] = a[0];
        dp[1] = a[1];
        for (int i=2; i<=n; i++) {
            dp[i] = min(dp[i-1],dp[i-2]);
            dp[i] += a[i];
        }
        return dp[n];        
    }
};