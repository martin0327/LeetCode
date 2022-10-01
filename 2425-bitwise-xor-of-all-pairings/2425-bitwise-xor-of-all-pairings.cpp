class Solution {
public:
  int xorAllNums(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    int ret = 0;
    for (int i=0; i<30; i++) {
      long long cnt = 0;
      for (auto x : a) if ((x>>i)&1) cnt += m&1;
      for (auto x : b) if ((x>>i)&1) cnt += n&1;
      ret |= ((cnt&1)<<i);
    }
    
    return ret;
  }
};