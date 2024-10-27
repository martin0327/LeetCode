using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    
    int countSquares(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;;
        vvi dp(n+1, vi(m+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (a[i-1][j-1] == 1) {
                    ans += dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }                
        return ans;        
    }
};