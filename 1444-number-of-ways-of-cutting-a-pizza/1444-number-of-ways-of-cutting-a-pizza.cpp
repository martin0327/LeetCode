using ll = long long;
const ll mod = 1e9+7;

class Solution {
public:
  ll suf[51][51];
  ll dp[10][50][50];
  int ways(vector<string>& a, int k) {
    int n = a.size(), m = a[0].size();    
    for (int i=n-1; i>=0; i--) {
      for (int j=m-1; j>=0; j--) {
        suf[i][j] = (a[i][j]=='A') + suf[i][j+1] + suf[i+1][j] - suf[i+1][j+1];
      }
    }    
    if (suf[0][0] < k) return 0;
    dp[0][0][0] = 1;
    for (int l=0; l<k-1; l++) {
      for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
          for (int ni=i+1; ni<n; ni++) {
            if ((suf[ni][j] >= k-l-1) && (suf[i][j] - suf[ni][j] > 0)) {
              dp[l+1][ni][j] += dp[l][i][j];
              dp[l+1][ni][j] %= mod;
            }
          }
          for (int nj=j+1; nj<m; nj++) {
            if ((suf[i][nj] >= k-l-1) && (suf[i][j] - suf[i][nj] > 0)) {
              dp[l+1][i][nj] += dp[l][i][j];
              dp[l+1][i][nj] %= mod;
            }
          }
        }
      }
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        ans += dp[k-1][i][j];
        ans %= mod;
      }
    }     
    return ans;
  }
};