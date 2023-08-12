class Solution {
public:
    int change(int k, vector<int>& c) {
        int n = c.size();
        vector<int> dp(k+1);
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j+c[i]<=k; j++) {
                dp[j+c[i]] += dp[j];
            }
        }
        return dp[k];
    }
};