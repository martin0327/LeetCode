class Solution {
public:
  int earliestFullBloom(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<pair<int,int>> c(n);
    for (int i=0; i<n; i++) {
      c[i] = {b[i],a[i]};
    }
    sort(c.rbegin(), c.rend());
    int cur = 0, ans = 0;
    for (auto [x,y] : c) {
      ans = max(ans, cur + x + y);
      cur += y;
    }
    return ans;
  }
}; 