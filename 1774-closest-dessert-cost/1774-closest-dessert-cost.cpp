using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int closestCost(vector<int>& a, vector<int>& b, int t) {
        int n = a.size(), m = b.size();
        for (int i=0; i<m; i++) b.push_back(b[i]);
        m = b.size();
        int mx = 2e4;
        vvi dp(m+1, vi(mx+1)); // 20 *2e4 = 4e5
        dp[0][0] = 1; // when I have used 0 topping, cost 0 is the only achievable cost
    
        for (int i=0; i<m; i++) {
            dp[i+1] = dp[i];
            for (int j=0; j<mx; j++) {
                if (dp[i][j]==0) continue;
                if (j+b[i] <= mx) dp[i+1][j+b[i]] = 1;
            }
            // print(dp[i]);
        }
        const int inf = 1e9;
        int d = inf, ans = inf;
        for (auto x : a) {
            for (int j=0; j<=mx; j++) {
                if (dp[m][j]) {
                    int c = x + j;
                    if (abs(c-t) < d) {
                        d = abs(c-t);
                        ans = c;
                    }
                    else if (abs(c-t) == d) {
                        ans = min(ans, c);
                    }
                }
            }
        }
        return ans;
    }
};








