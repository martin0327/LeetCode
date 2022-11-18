class Solution {
public:
  bool isUgly(int n) {
    if (n<=0) return false;
    for (int i=2; i<=5; i++) {
      while (!(n%i)) n /= i;
    }
    return n==1;
  }
};