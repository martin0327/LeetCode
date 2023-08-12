class Solution {
public:
  using vi = vector<int>;
  using vvi = vector<vi>;
  vi dr = {0,1};
  vi dc = {1,0};
  
  int uniquePathsWithObstacles(vector<vector<int>>& a) {
    if (a[0][0] == 1) return 0;
    int n = a.size();
    int m = a[0].size();
    vvi dp(n, vi(m));
    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        for (int k=0; k<2; k++) {
          int nr = i + dr[k];
          int nc = j + dc[k];
          if (nr < 0 || nr >= n) continue;
          if (nc < 0 || nc >= m) continue;
          if (a[nr][nc] == 1) continue;
          dp[nr][nc] += dp[i][j];
        }
      }
    }
    return dp[n-1][m-1];
  }
};