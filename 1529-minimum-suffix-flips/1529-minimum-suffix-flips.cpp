class Solution {
public:
  int minFlips(string t) {
    int ans = 0, x = 1;
    for (auto c : t) {
      if (c == x+'0') {
        x ^= 1;
        ans++;
      }
    }
    return ans;
  }
};
