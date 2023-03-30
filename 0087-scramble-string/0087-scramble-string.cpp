class Solution {
public:
  bool isScramble(string s, string t) {
    int n = s.size();
    int dp[30][30][30][30];
    memset(dp, -1, sizeof(dp));

    function<int(int,int,int,int)> f = [&](int l1, int r1, int l2, int r2) -> int{
      if (dp[l1][r1][l2][r2] != -1) return dp[l1][r1][l2][r2];
      if (l1==r1) {
        return dp[l1][r1][l2][r2] = (s[l1]==t[l2]);
      }
      int ret = 0;
      for (int i=0; i<r1-l1; i++) {
        ret |= f(l1,l1+i,l2,l2+i) && f(l1+i+1,r1,l2+i+1,r2);
        ret |= f(l1+i+1,r1,l2,l2+(r1-(l1+i+1))) && f(l1,l1+i,r2-i,r2);
      }
      return dp[l1][r1][l2][r2] = ret;
    }; 
    bool ans = f(0,n-1,0,n-1);
    return ans;
  }
};