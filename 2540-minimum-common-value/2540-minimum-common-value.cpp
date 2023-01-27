class Solution {
public:
  int getCommon(vector<int>& a, vector<int>& b) {
    set<int> s(a.begin(), a.end());
    for (auto x : b) {
      if (s.count(x)) return x;
    }
    return -1;
  }
};