using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
    int n = r.size(), m = c.size(), i=0, j=0;
    vvi ret(n, vi(m));
    while (i<n && j<m) {
      ret[i][j] = min(r[i],c[j]);
      if (r[i] < c[j]) c[j] -= r[i++];
      else r[i] -= c[j++];
    }
    return ret;
  }
};

