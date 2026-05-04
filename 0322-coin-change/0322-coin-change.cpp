class Solution {
public:
  using ll = long long;
  using vi = vector<ll>;
  using vvi = vector<vi>;
  const ll inf = 1e18;    
    
    
  int coinChange(vector<int>& a, int k) {

    int n = a.size();
    vi dp(k+1, inf);
    
    dp[0] = 0;
    for (int i=1; i<=k; i++) {
      for (int j=0; j<n; j++) {
        if (i >= a[j]) dp[i] = min(dp[i], 1 + dp[i-a[j]]);
      }
    }
    ll ans = dp[k];
    if (ans==inf) ans = -1;
    return ans;

  }
};