class Solution {
public:
  int maxCount(vector<int>& b, int n, int lim) {
    int ans = 0;
    set<int> s;
    for (auto x : b) s.insert(x);
    int x = 0;
    for (int i=1; i<=n; i++) {
      if (s.count(i)) continue;
      if (x+i <= lim) {
        x += i;
        ans++;
      }
      else break;
    }
    return ans;
  }
};