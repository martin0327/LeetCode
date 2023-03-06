class Solution {
public:
  vector<int> divisibilityArray(string s, int m) {
    vector<int> ret;
    long long cur = 0;
    for (auto c : s) {
      cur *= 10;
      cur += c - '0';
      cur %= m;
      ret.push_back(cur%m==0);
    }
    return ret;
  }
};