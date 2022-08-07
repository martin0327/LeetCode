class Solution {
public:
    using ll = long long;
    using vi = vector<ll>;
    using vvi = vector<vi>;
    const ll mod = 1e9+7;
    
    int countVowelPermutation(int n) {
        vvi dp(n, vi(5));
        for (int j=0; j<5; j++) dp[0][j] = 1;
        for (int i=1; i<n; i++) {
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
            dp[i][1] = (dp[i][1] + dp[i-1][0] + dp[i-1][2]) % mod;
            dp[i][3] = (dp[i][3] + dp[i-1][2] + dp[i-1][4]) % mod;
            dp[i][4] = (dp[i][4] + dp[i-1][0]) % mod ;
            for (int j=0; j<5; j++) 
                dp[i][2] = (dp[i][2] + dp[i-1][j]) % mod;
            dp[i][2] = (dp[i][2] + mod - dp[i-1][2]) % mod;
        }
        ll ans = 0;
        for (int j=0; j<5; j++) {
            ans += dp[n-1][j];
            ans %= mod;
        }
        return ans;
    }
};