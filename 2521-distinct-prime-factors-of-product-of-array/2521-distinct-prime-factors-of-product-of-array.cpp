class Solution {
public:
  int distinctPrimeFactors(vector<int>& a) {
    set<int> s;
    for (auto x : a) {
      for (int i=2; i*i<=x; i++) {
        while (x % i == 0) {
          s.insert(i);
          x /= i;
        }
      }
      if (x > 1) s.insert(x);
    }
    return s.size();
  }
};