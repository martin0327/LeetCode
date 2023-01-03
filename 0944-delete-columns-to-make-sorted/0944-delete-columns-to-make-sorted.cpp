class Solution {
public:
  int minDeletionSize(vector<string>& a) {
    int n = a.size();
    int m = a[0].size();
    int ans = 0;
    for (int j=0; j<m; j++) {
      bool ok = true;
      for (int i=1; i<n; i++) {
        if (a[i][j] < a[i-1][j]) ok = false;
      }
      if (!ok) ans++;
    }
    return ans;
  }
};