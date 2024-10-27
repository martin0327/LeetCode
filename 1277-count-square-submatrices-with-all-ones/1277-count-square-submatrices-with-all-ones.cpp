using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    
    int countSquares(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        vvi dp(m, vi(n));
        
        for (int i=0; i<m; i++) {
            dp[i][0] = a[i][0];
        }
        for (int j=0; j<n; j++) {
            dp[0][j] = a[0][j];
        }
        
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (a[i][j] == 1) {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + a[i][j];    
                }
            }
        }
        
        
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans += dp[i][j];
            }
        }
        
        return ans;

        
    }
};