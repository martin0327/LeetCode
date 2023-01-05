using pii = pair<int,int>;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
      int n = a.size();
      vector<pii> b(n);
      for (int i=0; i<n; i++) {
        b[i] = {a[i][1],a[i][0]};
      }
      sort(b.begin(), b.end());
      int ans = 0;
      long long last = -1e18;
      for (auto [r,l] : b) {
        if (l>last) {
          last = r;
          ans++;
        }
      }
      return ans;
    }
};