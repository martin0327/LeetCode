class Solution {
public:
  int maximum69Number (int x) {
    string s = to_string(x);
    for (auto &c : s) if (c=='6') {
      c = '9';
      break;
    }
    return stoi(s);
  }
};