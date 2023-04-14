using vi = vector<int>;
using vvi = vector<vi>;
void chmax(int &x, int y) {x = max(x,y);}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vvi dp(n+1, vi(n+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                chmax(dp[i][j], dp[i-1][j]);
                chmax(dp[i][j], dp[i][j-1]);
                chmax(dp[i][j], dp[i-1][j-1] + (s[i-1]==t[j-1]));
            }
        }
        int ans = 0;
        for (int i=0; i<=n; i++) {
            if (n-i>=0) chmax(ans,2*dp[i][n-i]);
            if (n-i>=1) chmax(ans,2*dp[i][n-i-1]+1);
        }
        return ans;
    }
};