using ll = long long;
using vi = vector<int>;
class Solution {
public:
    int change(int k, vector<int>& c) {
        ll n = c.size();
        vector dp(n+1, vi(k+1));
        dp[0][0] = 1;
        for (int i=0; i<n; i++) {
            dp[i+1] = dp[i];
            for (int j=0; j<k; j++) {
                for (int l=c[i]; j+l<=k; l+=c[i]) {
                    dp[i+1][j+l] += dp[i][j];
                }
            }
        }
        return dp[n][k];        
    }
};