class Solution {
public:
    double new21Game(int n, int k, int m) {
        using ld = long double;
        int sz = max(n,k+m);

        vector<ld> dp(sz+1);
        for (int i=k; i<=sz; i++) {
            if (i <= n) dp[i] = 1; // the probability that you get yes if you start at score i
        }
        ld cur = 0;
        for (int i=k; i<min(k+m,sz+1); i++) {
            cur += dp[i];
        }
        for (int i=k-1; i>=0; i--) {
            dp[i] = cur / (ld) m;
            if (i+m <=sz ) cur -= dp[i+m];
            cur += dp[i];
        }
        return dp[0];
    }
};