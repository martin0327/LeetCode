class Solution {
public:
  int countPartitions(vector<int>& a, int _k) {   
    using ll = long long;
    using vi = vector<ll>;
    using vvi = vector<vi>;
    const ll mod = 1e9+7;

    ll n = a.size();
    ll k = _k;
    vvi dp(n+1, vi(k+1));
    dp[0][0] = 1;
    ll cum = 0, nj;
    for (ll i=0; i<n; i++) {
      for (ll j=0; j<=min(k,cum); j++) {
        nj = min({j+a[i],cum-j,k});   
        dp[i+1][nj] += dp[i][j];
        dp[i+1][nj] %= mod;

        nj = min({j,cum-j+a[i],k});
        dp[i+1][nj] += dp[i][j];
        dp[i+1][nj] %= mod;
      }
      cum += a[i];
    }
    return dp[n][k];
  }
};