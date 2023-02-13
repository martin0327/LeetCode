class Solution {
public:
  int balancedStringSplit(string s) {
    int ans=0, x=0;
    for (auto c : s) {
      if ((x += c=='R'?1:-1) == 0) ans++;
    }
    return ans;
  }
};