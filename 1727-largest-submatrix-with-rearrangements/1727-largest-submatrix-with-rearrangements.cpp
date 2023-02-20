using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vvi b(m, vi(n));
    for (int j=0; j<m; j++) {
      for (int i=n-1; i>=0; i--) {
        if (i==n-1) b[j][i] = a[i][j];
        else {
          if (a[i][j]) b[j][i] = b[j][i+1] + 1;
        }
      }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
      vi c;
      for (int j=0; j<m; j++) {
        c.push_back(b[j][i]);
      }
      sort(c.rbegin(), c.rend());
      int h = 1e9;
      for (int j=0; j<m; j++) {
        h = min(h, c[j]);
        ans = max(ans, h * (j+1));
      }
    }
    return ans;
  }
};