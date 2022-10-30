class Solution {
public:
  int averageValue(vector<int>& a) {
    int s = 0;
    int n = 0;
    for (auto x : a) {
      if (x % 6 == 0) {
        s += x;
        n++;
      }
    }
    int ans = 0;
    if (n > 0) ans = s / n;
    return ans;
  }
};