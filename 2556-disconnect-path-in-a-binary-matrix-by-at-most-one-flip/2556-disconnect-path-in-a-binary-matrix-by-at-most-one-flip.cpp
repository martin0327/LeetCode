using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    if (n*m <= 2) return false;
    
    vvi b(n, vi(m)), c(n, vi(m)); 
    b[0][0] = 1; c[n-1][m-1] = 1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (a[i][j]) {
          if (i) b[i][j] |= b[i-1][j];
          if (j) b[i][j] |= b[i][j-1];
        }
      }
    }
    for (int i=n-1; i>=0; i--) {
      for (int j=m-1; j>=0; j--) {
        if (a[i][j]) {
          if (i+1<n) c[i][j] |= c[i+1][j];
          if (j+1<m) c[i][j] |= c[i][j+1];
        }
      }
    }
    
    
    bool ans = false;
    for (int k=1; k<n+m-2; k++) {
      int cnt = 0;
      for (int i=0; i<=k; i++) {
        int j = k - i;
        if (i >= n || j >= m) continue;
        if (a[i][j] && b[i][j] && c[i][j]) cnt++;
      }
      ans |= cnt <= 1;
    }
    return ans;
  }
};