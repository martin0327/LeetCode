class Solution {
public:
  string makeGood(string s) {
    int d = abs('a' - 'A');
    string ret;
    for (auto c : s) {
      if (ret.empty() || abs(ret.back() - c) != d) ret.push_back(c);
      else ret.pop_back();
    }
    return ret;
  }
};