class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> ret;
    int i=0, j=0, n=a.size(), m=b.size();
    while (i<n || j<m) {
      if (i<n && j<m) {
        if (a[i][0] == b[j][0]) {
          ret.push_back({a[i][0], a[i++][1] + b[j++][1]});
        }
        else if (a[i][0] < b[j][0]) ret.push_back(a[i++]);
        else ret.push_back(b[j++]);
      }
      else if (i<n) ret.push_back(a[i++]);
      else ret.push_back(b[j++]);
    }
    return ret;
  }
};  