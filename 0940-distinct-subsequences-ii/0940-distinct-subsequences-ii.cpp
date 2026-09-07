const int mod = 1e9+7, sz = 26;
int dp[sz];
class Solution {
public:
    int distinctSubseqII(string s) {
        fill(dp,dp+sz,1);
        int ans = 0;
        for (auto &ch : s) {
            int x = ch - 'a';
            ans += dp[x];
            ans %= mod;
            for (int y=0; y<sz; y++) {
                if (y == x) continue;
                dp[y] += dp[x];
                dp[y] %= mod;
            }
        }
        return ans;
    }
};