class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& b) {
    int ans = 0; 
    for (auto x : a) if (!(x&1)) ans += x;
    vector<int> res;
    for (auto q : b) {
      int val = q[0];
      int idx = q[1];
      if (!(a[idx]&1)) ans -= a[idx];
      a[idx] += val;
      if (!(a[idx]&1)) ans += a[idx];
      res.push_back(ans);
    }
    return res;
  }
};
