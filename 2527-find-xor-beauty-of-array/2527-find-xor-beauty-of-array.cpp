class Solution {
public:
    int xorBeauty(vector<int>& a) {
      int ret = 0;
      for (auto x : a) ret ^= x;
      return ret;
    }
};