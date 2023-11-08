class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& a, int t) {
        vector<int> dp(t+1,-1);
        dp[0] = 0;
        for (auto x : a) {
            for (int i=t-x; i>=0; i--) {
                if (dp[i] == -1) continue;
                dp[i+x] = max(dp[i+x], dp[i]+1);
            }
        }
        return dp[t];
    }
};