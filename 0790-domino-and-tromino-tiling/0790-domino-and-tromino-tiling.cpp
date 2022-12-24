class Solution {
public:
    int numTilings(int n) {
        const int mod = 1e9+7;
        vector<long long> dp(n+1);
        vector<long long> dp2(n+1);
        if (n==1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp2[0] = 0;
        dp2[1] = 1;
        dp2[2] = 2;
        for (int i=3; i<=n; i++) {
            dp2[i] = (dp2[i-1] + dp[i-1]) % mod;
            dp[i] = (2*dp2[i] - (dp[i-1] + dp[i-2]))  % mod;
            dp[i] += mod;
            dp[i] %= mod;
        }
        return dp[n];
    }
};