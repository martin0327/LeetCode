class Solution {
public:
    string breakPalindrome(string s) {
      int n = s.size();
      if (n==1) return "";
      for (int i=0; i<n/2; i++) {
        if (s[i]!='a') {
          s[i] = 'a';
          return s;
        }
      }
      s.back() = 'b';
      return s;
    }
}; 