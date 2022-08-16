class Solution {
public:
  int dp[11][(1<<10)][2][2];
  
  int countSpecialNumbers(int m) {
    string s = to_string(m);
    int n = s.size();
    s = ' ' + s;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) a[i] = s[i] - '0';
    
    dp[0][0][0][0] = 1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<(1<<10); j++) {
        for (int k=0; k<2; k++) {
          for (int l=0; l<2; l++) {
            for (int h=0; h<=(k?9:a[i+1]); h++) {
              if (l==1) {
                if (((j>>h)&1) == 0) dp[i+1][j | (1<<h)][k | (h < a[i+1])][l] += dp[i][j][k][l];
              }
              else {
                if (h==0) dp[i+1][j][k | (h < a[i+1])][l] += dp[i][j][k][l];
                else dp[i+1][j | (1<<h)][k | (h < a[i+1])][1] += dp[i][j][k][l];
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int j=2; j<(1<<10); j++) {
      for (int k=0; k<2; k++) {
        for (int l=0; l<2; l++) {
          ans += dp[n][j][k][l];
        }
      }
    }
    return ans;
  }
};