class Solution {
public:
  int minImpossibleOR(vector<int>& a) {
    for (int i=0; i<30; i++) {
      bool found = false;
      for (auto x : a) if (x==(1<<i)) found = true;
      if (!found) return (1<<i);
    }
    return 1<<29+1;
  }
};
/*
0001
0011
0110

*/
