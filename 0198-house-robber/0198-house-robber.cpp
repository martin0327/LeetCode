class Solution {
public:
  int rob(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n);
    dp[0] = a[0];
    for (int i=1; i<n; i++) {
      dp[i] = max(dp[i-1], a[i] + (i>1 ? dp[i-2] : 0));
    }
    return dp[n-1];
  }
}; 