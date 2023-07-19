class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
      int n = a.size();
      vector<pair<int,int>> b;
      for (auto x : a) {
        b.push_back({x[1],x[0]});
      }
      sort(b.begin(), b.end());
      int cur = -1e9;
      int ans = 0;
      for (auto [r,l] : b) {
        if (l < cur) continue;
        cur = r;
        ans++; 
      }
      return n-ans;
    }
};