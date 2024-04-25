class Solution {
public:
    int longestIdealString(string s, int K) {
        int n = s.size();
        s = ' ' + s;
        using vi = vector<int>;
        using vvi = vector<vi>;
        vvi dp(n+1, vi(26));
        for (int i=1; i<=n; i++) {
            int x = s[i] - 'a';
            for (int j=0; j<26; j++) {
                if (j==x) {
                    dp[i][j] = dp[i-1][j];
                    for (int k=0; k<26; k++) {
                        int jj = min(j,k);
                        int kk = max(j,k);
                        if (abs(j-k) <= K) {
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + 1);
                        } 
                    }
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int ans = 0;
        for (int j=0; j<26; j++) ans = max(ans, dp[n][j]);
        return ans;
    }
};