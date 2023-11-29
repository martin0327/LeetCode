const int inf = 1e9;
class Solution {
public:
    int minimumCoins(vector<int>& a) {
        int n = a.size();
        a.insert(a.begin(), 0);
        vector<int> dp(n+1,inf);
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            int r = min(2*i,n);
            for (int j=i; j<=r; j++) {
                dp[j] = min(dp[j], dp[i-1]+a[i]);
            }
        }
        return dp[n];        
    }
};