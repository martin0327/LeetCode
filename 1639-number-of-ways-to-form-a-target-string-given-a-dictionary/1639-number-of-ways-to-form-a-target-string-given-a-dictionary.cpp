using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 1e9+7;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.size();
        vi a(n);
        for (int i=0; i<n; i++) a[i] = target[i] - 'a';
        
        int m = words[0].size();
        vvi b(26, vi(m));
        for (auto x : words) {
            for (int j=0; j<m; j++) {
                b[x[j]-'a'][j]++;
            }
        }
        
        vvi dp(n+1, vi(m+1));
        dp[0] = vi(m+1, 1);
        for (int i=0; i<n; i++) {
            for (int j=i; j<m; j++) {
                dp[i+1][j+1] = dp[i][j] * b[a[i]][j] + dp[i+1][j];
                dp[i+1][j+1] %= mod;
            }
        }
        
        return dp[n][m];
    }
};