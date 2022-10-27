class Solution {
public:
  int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    int ans = 0;
    for (int dr=-n+1; dr<n; dr++) {
      for (int dc=-n+1; dc<n; dc++) {
        int cnt = 0;
        for (int r=0; r<n; r++) {
          for (int c=0; c<n; c++) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nr >= n) continue;
            if (nc < 0 || nc >= n) continue;
            if (a[nr][nc] && b[r][c]) cnt++;
          }
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};