class Solution {
public:
  int maximumXOR(vector<int>& a) {
    int ans = 0;
    int n = a.size();
    for (auto x : a) {
      for (int i=0; i<30; i++) {
        if ((x>>i)&1) ans |= (1<<i);
      }
    }
    return ans;
  }
};