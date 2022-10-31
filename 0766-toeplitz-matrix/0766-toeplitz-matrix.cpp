class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    map<int,set<int>> mp;
    for (int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        mp[j-i].insert(a[i][j]);
      }
    }
    for (auto &[k,v] : mp) {
      if (v.size()>1) return false;
    }
    return true;
  }
};