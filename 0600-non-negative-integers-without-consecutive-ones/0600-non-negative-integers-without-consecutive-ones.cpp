using vi = vector<int>;
using vvi = vector<vi>;
const int sz = 32;
int dp[sz][2][2][2];
class Solution {
public:
    int findIntegers(int n) {
        vi a;
        while (n) {
            a.push_back(n&1);
            n >>= 1;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0] = 1;
        reverse(a.begin(), a.end());
        n = a.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                for (int l=0; l<2; l++) {
                    for (int c=0; c<2; c++) {
                        if (dp[i][j][l][c] == 0) continue;
                        for (int d=0; d<=(j?1:a[i]); d++) {
                            int nj = j | d < a[i];
                            int nl = d;
                            int nc = c | (d == 1 && l == 1);
                            dp[i+1][nj][nl][nc] += dp[i][j][l][c];
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int j=0; j<2; j++) {
            for (int l=0; l<2; l++) {
                ans += dp[n][j][l][0];
            }
        }
        return ans;
    }
};