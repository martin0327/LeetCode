using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vvi b(n, vi(m));
    for (int j=0; j<m; j++) {
      for (int i=n-1; i>=0; i--) {
        if (i==n-1) b[i][j] = a[i][j];
        else if (a[i][j]) b[i][j] = b[i+1][j] + 1;
      }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
      sort(b[i].rbegin(), b[i].rend());
      int h = 1e9;
      for (int j=0; j<m; j++) {
        h = min(h, b[i][j]);
        ans = max(ans, h * (j+1));
      }
    }
    return ans;
  }
};