class Solution {
public:
  int f(int x) {
    int ret = 0;
    for (int i=2; i*i<=x; i++) {
      while (x % i == 0) {
        x /= i;
        ret += i;
      }
    }
    if (x > 1) ret += x;
    return ret;
  }
  int smallestValue(int n) {
    while (true) {
      int x = f(n);
      if (n==x) break;
      else n = x;
    }
    return n;
  }
};