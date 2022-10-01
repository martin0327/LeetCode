class Solution {
public:
  int dp[101];
  int numDecodings(string s) {
    if (s[0] == '0') return 0;

    int n = s.size();
    s = '0' + s;
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
      if (s[i] != '0') dp[i] += dp[i-1];
      if (i>=2) {
        int x = stoi(s.substr(i-1,2));
        if (10<=x && x<=26) dp[i] += dp[i-2];
      }
    }
    return dp[n];
  }
};