class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& b) {
    int ans = 0; 
    for (auto x : a) if (~x&1) ans += x;
    vector<int> res;
    for (auto q : b) {
      int v = q[0];
      int i = q[1];
      if (~a[i]&1) ans -= a[i];
      a[i] += v;
      if (~a[i]&1) ans += a[i];
      res.push_back(ans);
    }
    return res;
  }
};