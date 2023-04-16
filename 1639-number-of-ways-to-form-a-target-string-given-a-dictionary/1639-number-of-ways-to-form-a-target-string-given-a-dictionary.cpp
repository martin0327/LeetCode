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
        vvi dp(n+1, vi(m+1));
        dp[0] = vi(m+1, 1);
        for (int i=0; i<n; i++) {
            for (int j=i; j<m; j++) {
                dp[i+1][j+1] = dp[i][j] * b[j][a[i]-'a'] + dp[i+1][j];
                dp[i+1][j+1] %= mod;
            }
        }
        return dp[n][m];
    }
};
