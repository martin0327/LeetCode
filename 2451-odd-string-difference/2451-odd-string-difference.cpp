class Solution {
public:
  string oddString(vector<string>& a) {
    int n = a.size();
    int m = a[0].size();
    map<vector<int>, vector<string>> mp;
    for (int i=0; i<n; i++) {
      vector<int> temp;
      for (int j=0; j<m-1; j++) {
        temp.push_back(a[i][j+1] - a[i][j]);
      }
      mp[temp].push_back(a[i]);
    }
    for (auto &[k,v] : mp) {
      if (v.size()==1) {
        return v[0];
      }
    }
    return "";
  }
};