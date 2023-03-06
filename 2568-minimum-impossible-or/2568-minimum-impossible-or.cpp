class Solution {
public:
  int minImpossibleOR(vector<int>& a) {
    int y = 0;
    for (auto x : a) if (!(x & (x - 1))) y |= x;
    for (int i=0; i<30; i++) {
      if (!(y>>i&1)) return 1<<i; 
    }
    return 1<<30;
  }
};