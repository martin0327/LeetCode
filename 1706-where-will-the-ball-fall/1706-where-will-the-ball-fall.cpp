class Solution {
public:
  vector<int> findBall(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vector<int> ret(m);
    for (int k=0; k<m; k++) {
      int p = k;
      for (int i=0; i<n; i++) {
        int d = a[i][p];
        if (0 <= p+d && p+d < m && d+a[i][p+d]) p += d;
        else {
          p = -1; 
          break;
        }
      }
      ret[k] = p;
    }
    return ret;
  }
};      