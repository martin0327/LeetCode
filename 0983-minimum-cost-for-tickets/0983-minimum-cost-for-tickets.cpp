using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
void chmin(int &x, int y) {x = min(x,y);}
class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& c) {
    int n = 365, m = 30;
    vi a(n+1);
    vvi dp(n+1, vi(m,inf));
    for (auto d : days) a[d] = 1;
    dp[0][0] = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (j > 0 || a[i+1] == 0) chmin(dp[i+1][max(j-1,0)],dp[i][j]);
        chmin(dp[i+1][max(j-1,0)],dp[i][j]+c[0]);
        chmin(dp[i+1][max(j-1,6)],dp[i][j]+c[1]);
        chmin(dp[i+1][max(j-1,29)],dp[i][j]+c[2]);
      }
    }
    return *min_element(dp[n].begin(), dp[n].end());
  }
};