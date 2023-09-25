class Solution {
public:
    char findTheDifference(string s, string t) {
      char ret = 0;
      for (char x : s) ret ^= x;
      for (char x : t) ret ^= x;
      return ret;
    }
};