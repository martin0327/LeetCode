




class Solution {
public:
    long long minIncrementOperations(vector<int>& a, int k) {
        
        #define int long long
        using vi = vector<int>;
        using vvi = vector<vi>;
        const int inf = 2e18;
        
        int n = a.size();
        a.insert(a.begin(), 0);
        
        vvi dp(n+1, vi(2,inf));
        dp[0][0] = dp[0][1] = 0;
        for (int i=1; i<=n; i++) {
            int c = max(0, k - a[i]);
            {
                int t = inf;
                for (int j=1; j<=2; j++) {
                    if (i-j >= 0) t = min(t, dp[i-j][1]);
                }
                dp[i][0] = t;
            }
            {
                int t = inf;
                for (int j=1; j<=3; j++) {
                    if (i-j >= 0) t = min(t, dp[i-j][1]);
                    if (i-1 >= 0) t = min(t, dp[i-1][0]);
                    dp[i][1] = t + c;
                }
            }
        }
        int ans = dp[n][0];
        for (int i=n-2; i<=n; i++) ans = min(ans, dp[i][1]);
        return ans;
        
        #undef int
    }
};