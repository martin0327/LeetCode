class Solution {
public:
  vector<int> separateDigits(vector<int>& a) {
    vector<int> ret;
    for (auto x : a) {
      string s = to_string(x);
      for (auto c : s) {
        ret.push_back(c - '0');
      }
    }
    return ret;
  }
};