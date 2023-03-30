class Solution {
public:
  bool isScramble(string s, string t) {
    int n = s.size();
    int dp[n][n][n+1];
    memset(dp, -1, sizeof(dp));

    function<int(int,int,int)> f = [&](int i, int j, int sz) {
      if (dp[i][j][sz] != -1) return dp[i][j][sz];
      if (sz==1) return dp[i][j][sz] = (s[i]==t[j]);
      int ret = 0;
      for (int k=1; k<sz; k++) {
        ret |= f(i,j,k) && f(i+k,j+k,sz-k);
        ret |= f(i+k,j,sz-k) && f(i,j+sz-k,k);
      }
      return dp[i][j][sz] = ret;
    }; 

    return f(0,0,n);
  }
};