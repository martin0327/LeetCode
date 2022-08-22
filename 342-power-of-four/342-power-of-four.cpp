class Solution {
public:
  bool isPowerOfFour(int n) {
    int cnt = 0;
    while (n) {
      int r = n%4;
      if (r>1) return false;
      cnt += r==1;
      n /= 4;
    }
    return cnt==1;
  }
};