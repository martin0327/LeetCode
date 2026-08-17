class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1);
        for (int i=1; i*i<=n; i++) {
             dp[i*i] = 1;
        }
        for (int i=1; i<=n; i++) {
            if (dp[i]) continue;
            for (int j=1; j*j<=i; j++) {
                if (dp[i-j*j] == 0) dp[i] = 1;
            }
        }
        return dp[n];
    }
};