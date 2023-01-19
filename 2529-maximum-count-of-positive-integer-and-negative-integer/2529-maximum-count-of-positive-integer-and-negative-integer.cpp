class Solution {
public:
  int maximumCount(vector<int>& a) {
    int x = 0, y = 0;
    for (auto a : a) {
      if (a > 0) x++;
      else if (a < 0) y ++;
    }
    return max(x,y);
  }
};