class Solution {
public:
  vector<int> findBall(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vector<int> ret(m);
    for (int k=0; k<m; k++) {
      int p = k;
      for (int i=0; i<n; i++) {
        if (a[i][p] == 1) {
          if (p < m-1 && a[i][p+1] == 1) p++;
          else {
            p = -1;
            break;
          }
        }
        else {
          if (p > 0 && a[i][p-1] == -1) p--;
          else {
            p = -1;
            break;
          }
        }
      }
      ret[k] = p;
    }
    return ret;
  }
};    