using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const int mod = 1e9+7;

class Solution {
public:
    int numWays(vector<string>& words, string a) {
        int n = a.size();
        int m = words[0].size();

        vvi b(m, vi(26));
        for (auto x : words) {
            for (int i=0; i<m; i++) {
                b[i][x[i]-'a']++;
            }
        }
        vvi dp(n, vi(m));
        for (int j=0; j<m; j++) dp[0][j] = b[j][a[0]-'a'];
        for (int j=1; j<m; j++) dp[0][j] += dp[0][j-1];
        for (int i=1; i<n; i++) {
            for (int j=i; j<m; j++) {
                dp[i][j] = dp[i-1][j-1] * b[j][a[i]-'a'];
                dp[i][j] %= mod;
            }
            for (int j=i; j<m; j++) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
        return dp[n-1][m-1];
    }
};