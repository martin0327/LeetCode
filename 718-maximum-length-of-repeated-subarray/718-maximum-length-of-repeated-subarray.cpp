class Solution {
public:
  int findLength(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int dp[1001][1001];

    int ans = 0;
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
        dp[i][j] = (a[i-1]==b[j-1]) ? dp[i-1][j-1]+1 : 0;
        ans = max(ans, dp[i][j]);
      }
    }    
    
    return ans;
  }
};