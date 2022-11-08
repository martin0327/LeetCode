class Solution {
public:
  string makeGood(string s) {
    int d = abs('a' - 'A');
    string ret;
    for (auto c : s) {
      if (ret.size() && abs(ret.back() - c) == d) ret.pop_back();
      else ret.push_back(c);
    }
    return ret;
  }
}; 