class Solution {
public:
  string addBinary(string a, string b) {
    string ret;
    int x = 0;
    while (a.size() && b.size()) {
      int y = a.back() - '0'; 
      a.pop_back();
      int z = b.back() - '0'; 
      b.pop_back();
      int s = x+y+z;
      ret += (s&1) + '0';
      x = s / 2;
    }
    while (a.size()) {
      int s = x + a.back() - '0'; 
      a.pop_back();
      ret += (s&1) + '0';
      x = s / 2;
    }
    while (b.size()) {
      int s = x + b.back() - '0';
      b.pop_back();
      ret += (s&1) + '0';
      x = s / 2;
    }
    if (x) ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
  }
};