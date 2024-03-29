template<typename T>
void chmax(T &x, T y) {x = max(x,y);}
using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

class Solution {
public:
  int maxProfit(int m, vector<int>& a) {
    int n = a.size();
    m *= 2;
    vvi dp(n+1, vi(m+1,-inf));
    dp[0][0] = 0;
    int ans = 0;  
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (dp[i][j] == -inf) continue;
        chmax(dp[i+1][j],dp[i][j]);
        if (j&1) chmax(dp[i+1][j+1],dp[i][j]+a[i]);
        else chmax(dp[i+1][j+1],dp[i][j]-a[i]);
        chmax(ans, dp[i+1][j+1]);
      }
    }
    
    return ans;
  }
};