using ld = long double;
class Solution {
public:
    double new21Game(int n, int k, int lim) {
        vector<ld> dp(n+2);
        dp[0] = 1;
        for (int i=0; i<=n; i++) {
            if (i>1) dp[i] += dp[i-1];
            if (i < k) {
                dp[i+1] += dp[i] / lim;
                dp[min(i+lim+1,n+1)] -= dp[i] / lim;
            }
        }
        ld ans = 0;
        for (int i=k; i<=n; i++) ans += dp[i];
        return ans;
    }
};  